/*
 * algorithm_page_name.cpp
 *
 *  Created on: Jan 26, 2010
 *      Author: monfee
 */

#include "algorithm_page_name.h"
#include "algorithm_config.h"
#include "ant_link_parts.h"
#include "ant_link_term.h"
#include "ant_link_posting.h"
#include "link.h"
#include "language.h"
#include "corpus.h"
#include "ltw_task.h"
#include "string_utils.h"

#include <stdlib.h>

#include <fstream>
#include <utility>
#include <sstream>
#include <iostream>

using namespace std;

namespace QLINK
{

	algorithm_page_name::algorithm_page_name(ltw_task *task) : algorithm_out(task)
	{
		init();
	}

	algorithm_page_name::~algorithm_page_name()
	{
//		page_map_t::iterator iter = names_map_.begin();
//		for (; iter != names_map_.end(); ++iter) {
//			if (iter->second)
//				delete iter->second;
//		}
		for (int i = 0; i < name_array_.size(); ++i)
			delete name_array_[i];
	}

	void algorithm_page_name::init()
	{
		config_ = new algorithm_config;
		loaded_ = false;

		load_names();
	}

	void algorithm_page_name::load_names()
	{
		if (!config_ || loaded_)
			return;

		string filename(config_->get_value("titles_file"));
		if (filename.length() <= 0)
			return;

		ifstream myfile (filename.c_str());
		cerr << "loading file " << filename << endl;
		int count = 0;
		if (myfile.is_open()) {
			while (! myfile.eof()) {
				string line;
				getline (myfile, line);
				if (line.length() == 0 || line.find("Portal:") != string::npos)
					continue;
#ifdef DEBUG
				cerr << "loading : " << line << endl;
#endif
				string::size_type pos = line.find_first_of(':');
				if (pos != string::npos) {
					unsigned long doc_id = atol(line.c_str());
					if (!corpus::instance().exist(doc_id))
						continue;
					string wiki_title(line, ++pos);
					if (use_utf8_token_matching_ && strchr(wiki_title.c_str(), ' ') != NULL)
						find_and_replace(wiki_title, string(" "), string(""));

					std::pair<std::string, std::string> title_pair = wikipedia::process_title(wiki_title, lowercase_only/*, !use_utf8_token_matching_*/);
					//struct wiki_entry a_entry;
					ANT_link_posting *a_entry = new ANT_link_posting;
					a_entry->docid = doc_id;
					a_entry->desc = strdup(title_pair.second.c_str());
					a_entry->offset = 0;
					a_entry->link_frequency = 1;
					a_entry->doc_link_frequency = 1;
					//a_entry.id = doc_id;
					//a_entry.title = title_pair.first;
					//a_entry.description = title_pair.second;

//					page_map_t::iterator iter = names_map_.find(title_pair.first);
					ANT_link_term *index_term = this->find_term_in_list(title_pair.first.c_str());
					if (index_term == NULL || string_compare(index_term->term, title_pair.first.c_str()) != 0) {
//					if (iter == names_map_.end() || iter->second == NULL) {
						//wiki_entry_array wea;
//						if (index_term != NULL)
//							cerr << title_pair.first << " is a unique term to " << index_term->term << endl;

						ANT_link_term *term = new ANT_link_term;
						term->term = strdup(title_pair.first.c_str());
						term->total_occurences = 0;
						term->document_frequency = 9999;
						term->collection_frequency = 9999;
//						string& name = title_pair.first;

//						if (iter != names_map_.end() && iter->second == NULL)
//							iter->second = term;
//						else
//							iter = names_map_.insert(make_pair(name, term)).first;

//						string::size_type pos = name.find(' ');
//						if (pos != string::npos) {
//							string first_term(name, 0, pos);
//							page_map_t::iterator iner_iter = names_map_.find(first_term);
//							if (iner_iter == names_map_.end())
//								names_map_.insert(make_pair(first_term, (ANT_link_term *)NULL));
//	//						else
//	//							cerr << "found a match (" << iner_iter->first << ")" << endl;
//						}
						//result.second.push_back(a_entry);
						term->postings.push_back(a_entry);
						name_array_.push_back(term);
						++count;
					}
					else {
						index_term->postings.push_back(a_entry);
					}
				}
				else {
					cerr << "Error in line : " << line << endl;
				}

//			  cout << line << endl;
			}
//			std::sort(name_array_.begin(), name_array_.end(), ANT_link_term_compare());
			myfile.close();
			cerr << "loaded " << name_array_.size() << " entries, " << count << " recored" << endl;
		}

		// debug
	//	page_map_t::iterator iter = names_map_.begin();
	//	while (iter != names_map_.end()) {
	//		if (iter->second != NULL)
	//			for (int i = 0; i < iter->second->postings.size(); i++)
	//				cerr << iter->second->postings[i]->docid << ":"
	//						<< iter->first << "(" << iter->second->postings[i]->desc << ")" << endl;
	//		else
	//			cerr << "found a match (" << iter->first << ") for the easy indexing" << endl;
	//		++iter;
	//	}

		loaded_ = true;
	}

	ANT_link_term *algorithm_page_name::find_term_in_list(const char *value)
	{
	long low, high, mid;

	low = 0;
	high = name_array_.size();
	while (low < high)
		{
		mid = (low + high) / 2;
		if (string_compare(name_array_[mid]->term, value, use_utf8_token_matching_) < 0)
			low = mid + 1;
		else
			high = mid;
		}

	if ((low < name_array_.size()) && (string_compare(value, name_array_[low]->term, use_utf8_token_matching_) == 0))
		return name_array_[low];		// match
	else
		{
		if (low < name_array_.size())
			return name_array_[low];		// not found in list but not after the last term in the list
		else
			return NULL;
		}
	}

	void algorithm_page_name::process_terms(links *lx, char **term_list, const char *source)
	{
		recommend_anchors(lx, term_list, source);
		lx->sort_links_by_term();
	}

	void algorithm_page_name::process_terms(char **term_list, const char *source)
	{
		process_terms(links_, term_list, source);
	}

	void algorithm_page_name::add_link(ANT_link_term *index_term, char **term_list, long offset)
	{
		bool to_skip = false;
		long term_len = 0;

//		char buffer[1024 * 1024];
		if (stopword_no_ && !strpbrk(index_term->term, "- "))
			to_skip = language::isstopword(index_term->term);

		if (!to_skip) {
//			offset = assign_link_term(index_term, term_list);
			//fprintf(stderr, "%s -> %d ", last_index_entry->second->term, last_index_entry->second->postings[0]->docid);
//			if (!links_->find(buffer_))
				link * lnk = links_->push_link(NULL, offset, buffer_, index_term->postings[0]->docid, 0.0, index_term);
			}
	}
}
