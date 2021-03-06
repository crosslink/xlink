/******************************************************************************
 * This file is part of the XLINK - The Link Discovery Toolkit.
 * (c) Copyright 2013 Queensland University of Technology
 *
 * This file may be distributed and/or modified under the terms of the
 * BSD 3-cause LICENSE appearing in the file BSD.txt included in the
 * packaging of this file.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *******************************************************************************
 *
 * @author				Eric Tang
 *
 *******************************************************************************/
 /*
 * link.cpp
 *
 *  Created on: Aug 3, 2009
 *	@author orignially written by Andrew Trotman
 */

#include "link.h"
#include "link_print.h"
#include "ant_link_term.h"
#include "ant_link_posting.h"
#include "ant_link_parts.h"
#include "application_out.h"
#include "sys_file.h"
#include "corpus.h"
#include "algorithm.h"
#include "search_engine_ant_remote.h"
#include "translation.h"
#include "run_config.h"
#include "database_mysql.h"
#include "google_research_translator.h"

#include "xml.h"

#include <stdlib.h>
#include <string.h>

#include <string>
#include <iostream>
#include <vector>

using namespace QLINK;
using namespace std;

long link::fill_anchor_with_ir_results = 0;
long link::translate_anchor_for_linking = 0;
bool link::crosslink_me = false;

link::link() {
	place_in_file = NULL;
	term = NULL;
	link_term = NULL;
	to_clean_ = false;
	gamma = 0.0;
	offset = 0;
	target_document = -1;
	aout_ = NULL;
}

link::~link() {
	// segment fault if run below code
	// found out later
	if (term) {
		free(term);
		term = NULL;
	}
	if (to_clean_) {
		delete link_term;
		link_term = NULL;
	}
}

void link::print()
{
	print_header();
	//printf("%d", target_document);
	(*aout_) << target_document;
	print_footer();
}


bool link::print_target(long anchor, algorithm *algor)
{
	bool ret = true;
	if (algor != NULL)
		ret = algor->has_crosslink(link_term->postings[anchor]->docid);

	if (ret || fill_anchor_with_ir_results) {
		print_header();
		//printf("%d", link_term->postings[anchor]->docid);
		if (link_term->postings.size() > 0)
			(*aout_) << link_term->postings[anchor]->docid;
		else
			;
		print_footer();
	}
	return ret;
}

bool link::print_anchor(topic *topic_ptr, long beps_to_print, bool id_or_name, algorithm *algor)
{
	char buf[1024 * 10];
	int count = 0;
	bool anchor_printed = false;

	bool ret = false;
	if (!fill_anchor_with_ir_results && algor != NULL && algor->size_of_crosslink() > 0) {
		if (link_term->postings.size() > 0)
			for (int i = 0; i < link_term->postings.size(); i++) {
				if (algor->has_crosslink(link_term->postings[i]->docid)) {
					ret = true;
					break;
				}
			}
		else
			ret = algor->has_crosslink(target_document);
	}
	else
		ret = true;

	string tran;
	/*
	 * to someting with the this_term first;
	 */
	int term_length = strlen(term);
	string this_term = string_clean_tag(term, 0);
	trim_left(this_term, " ");
	trim_right(this_term, " ");

//	while (this_term.find("  ") != string::npos)
	find_and_replace(this_term, string("  "), string(" "));
	xmlify(this_term);

	long this_offset = offset;
	ANT_link_term *this_link_term = link_term;
	int how_many_left = beps_to_print;

	stringstream stringbuffer;

	if (ret && translate_anchor_for_linking == 2) {
		tran = translation::instance().translate(this_term.c_str(), (std::string(source_lang) + "|" + std::string(target_lang)).c_str());

		ANT_link_term *crossterm = NULL;
		if ((crossterm = algor->find_term_in_list(tran.c_str())) != NULL && string_compare(crossterm->term, tran.c_str(), TRUE) == 0)
			this_link_term = crossterm;
		else
			ret = false;
	}

	if (ret || fill_anchor_with_ir_results) {
		const char *format = link_print::target_format.c_str();

//		if (strcmp(term, "\"") == 0)
//			sprintf(buf, "\t\t\t<anchor offset=\"%d\" length=\"%d\" name=\"%s\">\n", this_offset, 1, "&quot;");
//		else
		sprintf(buf, "\t\t\t<anchor offset=\"%d\" length=\"%d\" name=\"%s\">\n", this_offset, term_length, this_term.c_str());

		std::string anchor_tag(buf);
		if ((fill_anchor_with_ir_results && fill_anchor_with_ir_results != 2) || (!fill_anchor_with_ir_results && this_link_term->postings.size() > 0)) {
			stringbuffer << anchor_tag;
			anchor_printed = true;
			for (int i = 0; i < this_link_term->postings.size(); i++) {
				if (this_link_term->postings[i]->docid < 0 && id_or_name)
					continue;

				unsigned long id = 0;
				if (id_or_name)
					id = this_link_term->postings[i]->docid;
				else
					id = atoi(this_link_term->postings[i]->desc);

				std::string target_title;
				if (crosslink_me) {
					if (algor != NULL && algor->size_of_crosslink() > 0)
						id = algor->get_crosslink(id);
					if (id <= 0)
						continue;
				}
				if (corpus::instance().exists()) {
					string filename = corpus::instance().id2docpath(id);
					if (!sys_file::exist(filename.c_str())) {
						cerr << "No target file found:" << filename << endl;
						continue;
					}
					target_title.append(corpus::instance().gettitle(filename));
				}
//				else
//				{
//					sprintf(buf, format, this_link_term->postings[i]->offset, id);
//				}
				sprintf(buf, format, 0, target_lang, target_title.c_str(), id);
				stringbuffer << buf << endl;
				++count;
				if (count >= beps_to_print)
					break;
			}
		}
		else
			ret = false;

		how_many_left = beps_to_print - count;
#ifdef WITH_ATIRE
		if (fill_anchor_with_ir_results && how_many_left > 0 && (how_many_left < beps_to_print)) {
			long long result = 0;
			string query;

//			if (strlen(term) == 0)
//				cerr << " I got you" << endl;

			if (!translate_anchor_for_linking) { // TODO: create a conditon here
				query = term;
			}
			else {
				// old Google API no longer available, needed re-impremented
				if (!google_research_translator::get_instance().is_initialized()) {
//					database_mysql::instance().connect();
					google_research_translator::get_instance().initialize(google_translator::LOAD_KEY);
					string lang_pair = string(source_lang) + ":" + string(target_lang);
					google_research_translator::get_instance().set_lang_pair(lang_pair.c_str());
				}
				query = google_research_translator::get_instance().get_translation(term); //translation::instance().translate(term, lang_pair.c_str());
			}

			vector<string> docids;
			bool found_hits = search_engine_ant_remote::instance().search(query.c_str(), &docids);

			int hits = docids.size(); // how_many_left > search_engine_ant::instance().hits() ? search_engine_ant::instance().hits() : how_many_left;
			ret = hits > 0;
			long doc_id = -1;
			if (hits > 0) {
				if (!anchor_printed) {
					stringbuffer << anchor_tag;
					anchor_printed = true;
				}
				ret = true;
			}
			else {
				ret = anchor_printed;
			}
			int num = hits > how_many_left ? how_many_left : hits;
			for (int i = 0; i < num; ++i) {
				doc_id = result_to_id(docids[i].c_str());
				if (doc_id < 1)
					continue;
				string filename = corpus::instance().id2docpath(doc_id);
				if (!sys_file::exist(filename.c_str())) {
					cerr << "No target file found:" << filename << endl;
					continue;
				}
				std::string target_title = corpus::instance().gettitle(filename);
				sprintf(buf, format, 0, target_lang, target_title.c_str(), doc_id);
				stringbuffer << buf;
				--how_many_left;
			}
		}
#endif

#ifdef DEBUG
		if (how_many_left < 4)
			cerr << "anchor (" << this_term << ") has more than 1 link." << endl;
#endif

		//puts("\t\t\t</anchor>\n");
		if (anchor_printed) {
			stringbuffer << "\t\t\t</anchor> " << endl;
			stringbuffer <<"\n";
		}
	}
	if (how_many_left == beps_to_print) {
		cerr << "No link outputed: there must be something funny happened for anchor \"" << term << "\" even with " << this_link_term->postings.size() << " links."<< endl;
		ret = false;
	}

	if (ret) {
		(*aout_) << stringbuffer.str();
//		const char *result_buf = stringbuffer.str().c_str();
//		aout_->printbuf(result_buf);
	}
	return ret;
}

void link::print_bep(long beps_to_print)
{
	char buf[255];
	if (!link_term) {
		sprintf(buf, "\t\t\t<bep offset=\"%d\">\n", 0);
		(*aout_) << buf;
		sprintf(buf, "\t\t\t\t<fromanchor offset=\"%d\" length=\"%d\" file=\"%d\">%s</fromanchor>\n",
				offset, strlen(term), target_document, term);
		(*aout_) << buf;
//		puts("\t\t\t</bep>\n");
		(*aout_) << "\t\t\t</bep>\n";
	}
	else {
		int count = 0;
		for (int i = 0; i < link_term->postings.size(); i++) {
			if (link_term->postings[i]->docid < 0)
				continue;

			sprintf(buf, "\t\t\t<bep offset=\"%d\">\n", link_term->postings[i]->offset);
			(*aout_) << buf;
			sprintf(buf, "\t\t\t\t<fromanchor offset=\"%d\" length=\"%d\" file=\"%d\">%s</fromanchor>\n",
					offset, strlen(term), target_document, term);
			(*aout_) << buf;
			//puts("\t\t\t</bep>\n");
			(*aout_) << "\t\t\t</bep>\n";
			++count;
			if (count >= beps_to_print)
				break;
		}
	}
}

/*
	LINK::COMPARE()
	-------------------
*/
bool link::compare(const link *one, const link *two)
{
	//link *one = NULL, *two = NULL;
	double diff = 0.0;
	bool cmp = false;

	//one = (link *)a;
	//two = (link *)b;

	diff = two->gamma - one->gamma;
	if (diff < 0)
		return false;
	else if (diff > 0)
		return true;

	if ((cmp = strcmp(one->term, two->term)) == 0)
		return one->place_in_file > two->place_in_file;
		//return one->place_in_file > two->place_in_file ? 1 : one->place_in_file == two->place_in_file ? 0 : -1;

	return cmp;
}

/*
	LINK::FINAL_COMPARE()
	-------------------------
*/
bool link::final_compare(const link *one, const link *two)
{
//link *one = NULL, *two = NULL;
double diff = 0.0;

//one = (link *)a;
//two = (link *)b;

diff = two->gamma - one->gamma;
if (diff < 0)
	return true;
else if (diff > 0)
	return false;
else
	return one->place_in_file > two->place_in_file; // ? 1 : one->place_in_file == two->place_in_file ? 0 : -1;
}

/*
	LINK::STRING_TARGET_COMPARE()
	---------------------------------
*/
bool link::string_target_compare(const link *one, const link *two)
{
//link *one = NULL, *two = NULL;
bool cmp = false;

//one = (link *)a;
//two = (link *)b;

if ((cmp = strcmp(one->term, two->term)) == 0)
	cmp = one->target_document > two->target_document;

return cmp;
}

/*
	LINK::TERM_COMPARE()
	---------------------------------
*/
bool link::term_compare(const link *one, const link *two)
{
//link *one = NULL, *two = NULL;
bool cmp;

//one = (link *)a;
//two = (link *)b;
int ret = 0;
long one_term_count = count_char(one->term, ' ') + 1;
long two_term_count = count_char(two->term, ' ') + 1;

if (one_term_count == two_term_count) {
	if (strlen(one->term) == strlen(two->term)) {
		if ((ret = strcmp(one->term, two->term)) == 0)
			cmp = one->target_document > two->target_document;
		else
			cmp = ret > 0;
	}
	else
		cmp = strlen(one->term) > strlen(two->term);
}
else
	cmp = one_term_count > two_term_count;

return cmp;
}

bool link::operator==(const link& rhs)
{
	return strcmp(rhs.term, this->term) == 0;
}

bool link::operator==(const char *term)
{
	int cmp = strcmp(this->term, term);
	return cmp == 0;
}

const bool link_string_target_compare::operator()(const link *a, const link * b) const
{
	// check for 0
	if (a == 0)
		return b == 0; // if b is also 0, then they are equal, hence b is not > than a
	else if (b == 0)
		return true;
	else {
		int cmp = 0;

		if ((cmp = strcmp(a->term, b->term)) == 0)
			cmp = a->target_document > b->target_document;

		return cmp > 0;
	}
}

const bool link_compare::operator() (const link *one, const link * two) const
{
	//link *one = NULL, *two = NULL;
	double diff = 0.0;

	//one = (link *)a;
	//two = (link *)b;

	diff = two->gamma - one->gamma;
	if (diff < 0)
		return true;
	else if (diff > 0)
		return false;
	else
		return two->target_document > one->target_document;
		//return one->place_in_file > two->place_in_file ? true : one->place_in_file == two->place_in_file ? one->target_document < two->target_document : false;
}

const bool term_compare::operator()(const link *one, const link *two) const
{
//link *one = NULL, *two = NULL;
bool cmp;

//one = (link *)a;
//two = (link *)b;
int ret = 0;
long one_term_count = count_char(one->term, ' ') + 1;
long two_term_count = count_char(two->term, ' ') + 1;

if (one_term_count == two_term_count) {
	if (strlen(one->term) == strlen(two->term)) {
		if ((ret = strcmp(one->term, two->term)) == 0)
			cmp = one->target_document > two->target_document;
		else
			cmp = ret > 0;
	}
	else
		cmp = strlen(one->term) > strlen(two->term);
		//cmp = one->target_document < two->target_document;
}
else
	cmp = one_term_count > two_term_count;

return cmp;
}
