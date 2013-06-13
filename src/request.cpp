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
 * request.cpp
 *
 *  Created on: 06/06/2013
 *
 */

#include "request.h"
#include "anchor.h"

#include <string>
#include <sstream>
#include <algorithm>

#include <stpl/stpl_stream.h>
#include <stpl/xml/stpl_xml.h>

#include <stdlib.h>

using namespace std;
using namespace stpl;

namespace QLINK {

request::request() : wikified_(false), last_request_time_(time(0)) {

}

request::request(const request& rsq) {
	this->last_request_time_ = rsq.get_last_request_time();
	this->page_ = rsq.get_page();
	this->url_ = rsq.get_url();
	this->wikified_ = rsq.is_wikified();
}

request::request(const char* url, const char* page) : url_(url), page_(page), wikified_(false), last_request_time_(time(0)) {

}

request::~request() {

}

void request::apply_links(const std::string& links_xml) {
	typedef XML::XParser<string, string::const_iterator> 		xml_parser;
	typedef xml_parser::document_type::entity_type	  			node_type;
	typedef xml_parser::document_type::entity_iterator 		entity_iterator;
	typedef xml_parser::document_type::element_type			element_type;
	xml_parser parser(links_xml.begin(), links_xml.end());
	parser.parse();

	xml_parser::document_type &doc = parser.doc();

	entity_iterator	it;

	for (it = doc.iter_begin(); it != doc.iter_end(); ++it) {
		node_type *node = static_cast<node_type*>((*it));
//		node->print();

		if (node->is_element()) {
			element_type *elem = static_cast<element_type *>(node);
			// debug
			elem->print();
			element_type *outgoing_links = elem->find_child("outgoing");

			if (outgoing_links != NULL) {
				cerr << "Total " << outgoing_links->size() << " anchors need to be processed!" << endl;

				entity_iterator anchor_it = outgoing_links->iter_begin();
				vector<anchor> anchor_array;

				while (anchor_it != outgoing_links->iter_end()) {
					element_type *anchor_elem = static_cast<element_type *>((*anchor_it));
					element_type *link = anchor_elem->find_child("tofile");
					if (link != NULL) {
						string name = anchor_elem->get_attribute("name");
						long	offset = atol(anchor_elem->get_attribute("offset").c_str());
						string target = link->text();

						if (offset > 0) {
							anchor ancr(name, offset);
							ancr.add_target(target);
							anchor_array.push_back(ancr);
						}
					}
					++anchor_it;
				}
				std::sort(anchor_array.begin(), anchor_array.end());
				stringstream wikified_page_ss("");
				string::size_type last_offset = 0;
				long last_anchor_len = 0;
				for (int i = 0; i < anchor_array.size(); ++i) {
					anchor &ancr = anchor_array[i];
					const string &name = ancr.get_name();
					const string &target = ancr.get_target();
					const string::size_type where  = ancr.get_offset();

					stringstream ss;
					ss << "<a href=\"http://en.wikipedia.org/w/api.php?curid=" << target << "\">" << name << "</a>";
//					string::size_type where = page_.find(ancr.get_name());
//					if (where != string::npos) {
//						page_.replace(where, where + name.length(), ss.str());
					string part = page_.substr(last_offset, where - last_offset);
#ifdef DEBUG
					cerr << part;
#endif

					wikified_page_ss << part << ss.str();
					last_offset = where + name.length();
//					}
//					else {
//						cerr << "Couldn't find " << name << " in the article." << endl;
//					}
				}
				wikified_page_ss << page_.substr(last_offset);
				wikified_page_ = wikified_page_ss.str();
				cerr << "finished wikify page" << endl;
			}
//			node->print();
		}
	}
}

} /* namespace QLINK */
