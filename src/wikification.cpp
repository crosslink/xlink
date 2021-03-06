/*
 * wikification.cpp
 *
 *  Created on: 14/06/2013
 *      Author: monfee
 */

#include "wikification.h"
#include "anchor.h"
#include "target.h"

#include <stpl/stpl_stream.h>
#include <stpl/xml/stpl_xml.h>

#include <algorithm>

#include <stdlib.h>

using namespace stpl;
using namespace std;

namespace QLINK {

wikification::wikification() {

}

wikification::~wikification() {

}

void wikification::linkify(const std::string& links_xml, const std::string& page, std::string& wikified_page) {
	linkify(links_xml.c_str(), page.c_str(), wikified_page);
}

void wikification::linkify(const char* links_xml,
		const char* page, std::string& wikified_page) {

	char *part = NULL;
	long article_len = strlen(page);
	long part_len = 0;
	stringstream wikified_page_ss("");

	typedef XML::XParser<string, const char*> 					xml_parser;
	typedef xml_parser::document_type::entity_type	  			node_type;
	typedef xml_parser::document_type::entity_iterator 		entity_iterator;
	typedef xml_parser::document_type::element_type			element_type;
	xml_parser parser(links_xml, links_xml + article_len);
	parser.parse();

	xml_parser::document_type &doc = parser.doc();

	entity_iterator	it;

	for (it = doc.iter_begin(); it != doc.iter_end(); ++it) {
		node_type *node = static_cast<node_type*>((*it));
//		node->print();

		if (node->is_element()) {
			element_type *elem = static_cast<element_type *>(node);
			// debug
//			elem->print();
			element_type *outgoing_links = elem->find_child("outgoing");

			if (outgoing_links != NULL) {
				cerr << "Total " << outgoing_links->size() << " anchors need to be processed!" << endl;

				entity_iterator anchor_it = outgoing_links->iter_begin();
				vector<anchor> anchor_array;

				while (anchor_it != outgoing_links->iter_end()) {
					element_type *anchor_elem = static_cast<element_type *>((*anchor_it));
					string name = anchor_elem->get_attribute("name");
					long	offset = atol(anchor_elem->get_attribute("offset").c_str());

					if (offset > 0) {
						/*
						 * TODO
						 * the  anchor offset is one byte offset from the real offset
						 * and I don't why, this is just a temporary fix
						 */
						anchor_array.push_back(anchor(name, offset));
						anchor& ancr = anchor_array.back(); //(name, offset);

						entity_iterator link_it = anchor_elem->iter_begin();
						while (link_it != anchor_elem->iter_end()) {
							element_type *link = static_cast<element_type *>((*link_it));; //anchor_elem->find_child("tofile");

	//						if (link != NULL) {
								string id = link->text();
								string title = link->get_attribute("title");
								string lang = link->get_attribute("lang");

								if (lang.length() == 0)
									lang = "en";

//								target a_target(lang, id, title);
								ancr.add_target(target(lang, id, title));
	//						}
							++link_it;
						}
					}
					++anchor_it;
				}
				std::sort(anchor_array.begin(), anchor_array.end());
#ifdef DEBUG
//				for (int i = 0; i <anchor_array.size(); ++i) {
//					anchor &ancr = anchor_array[i];
//					const string &name = ancr.get_name();
//					const target &a_target = ancr.get_target(i);
//					const string::size_type where  = ancr.get_offset();
//					cerr << "anchor: " << name << " offset: " << where << " target #: " << ancr.get_target_count() << endl;
//				}
//					cerr << "anchor: " << name << " offset: " << where << endl;
//					cerr << "last offset: " << last_offset << endl;
//					if (last_offset == 604)
//						cerr << endl;
#endif

				string::size_type last_offset = 0;
				long last_anchor_len = 0;
				for (int i = 0; i < anchor_array.size(); ++i) {
					anchor &ancr = anchor_array[i];
					const string &name = ancr.get_name();
					const target_type &a_target = ancr.get_target();
					const string::size_type where  = ancr.get_offset();

					if (where <= last_offset)
						continue;

//					string::size_type where = page.find(ancr.get_name());
//					if (where != string::npos) {
//						page.replace(where, where + name.length(), ss.str());
					if ((part_len = where - last_offset) < 0)
						break;

					part = new char[part_len + 1];
					memcpy(part, page + last_offset, part_len);
					part[part_len] = '\0';

					string anchor_name = string(page + where, name.length());
					last_offset = where + name.length();

					stringstream ss;
					stringstream url;
					stringstream ids;
					url << "http://en.wikipedia.org/w/index.php?curid=" << a_target.get_target();

					for (int i = 1; i < ancr.get_target_count(); ++i) {
						const target& tgt = ancr.get_target(i);
						if (i > 1)
							ids << ";";
						ids << tgt.get_lang() <<":" << tgt.get_target() << ":";
						if  (a_target.get_title().length() == 0)
							ids << tgt.get_target();
						else
							ids << tgt.get_title();
					}

					ss << "<a href=\"" << url.str() << "\" onmouseover=\"showWikiBox('" << a_target.get_lang() << "', '" <<  a_target.get_target() << "', '" << anchor_name << "'";
					if (ids.str().length() > 0)
						ss << ", '"  << ids.str() <<"'";
					ss << ")\">" << anchor_name << "</a>";

					wikified_page_ss << part << ss.str();
#ifdef DEBUG
//					cerr << "anchor: " << name << " offset: " << where << endl;
//					cerr << "last offset: " << last_offset << endl;
//					if (last_offset == 604)
//						cerr << endl;
//					cerr << part;
#endif
					delete [] part;
					ss.str("");
//					}
//					else {
//						cerr << "Couldn't find " << name << " in the article." << endl;
//					}
				}
				if ((part_len = article_len - last_offset) > 0) {
					part = new char[part_len + 1];
					memcpy(part, page + last_offset, part_len);
					part[part_len] = '\0';
					wikified_page_ss << part;
					delete [] part;
				}
			}
		}
	}
#ifdef DEBUG
//	cerr << wikified_page_ss.str() << endl;
#endif
	wikified_page.append(wikified_page_ss.str());
}

std::string wikification::linkify(const std::string& links_xml,
		const std::string& page) {
	string wikified_page;
	linkify(links_xml, page, wikified_page);
	return	wikified_page;
}

} /* namespace QLINK */
