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
#include "wikification.h"

#include <iostream>
#include <boost/regex.hpp>

using namespace std;

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
	static boost::regex pattern("<\\s+body\\s+>");
//	static string wikibox_scripts = string("<body><script type=\"text/javascript\" src=\"tooltip.js\"></script>\n <script type=\"text/javascript\" src=\"wikibox.js\"></script>");

	/*
	 *
	 */
	wikification::linkify(links_xml, page_, wikified_page_);

	/*
	 * adding tooltip scripts for anchors
	 */
//	wikified_page_ = boost::regex_replace (wikified_page_, pattern, wikibox_scripts);

	cerr << endl << "finished wikify page" << endl;
}

void request::inject_javascript(std::string& what) {
	string::size_type pos = 0; //= wikified_page_.find("body");
	string::iterator it_pre, it_next;
	while ((pos = wikified_page_.find("body", pos)) != string::npos && (pos + 4) < wikified_page_.length()) {
		it_pre = wikified_page_.begin() + pos;
		it_next = it_pre + 4;
		--it_pre;
		pos += 4;
//		++it_next;

		while (it_pre != wikified_page_.begin() && isspace(*it_pre))
			--it_pre;

		if (*it_pre == '<') {
			while (it_next != wikified_page_.end() && *it_next != '>')
				++it_next;
//				while (isspace(*it_next))

			if (*it_next == '>')
				wikified_page_.replace(it_pre, ++it_next, what/*wikibox_scripts*/);
			break;
		}
//		wikified_page_.insert(pos, wikibox_scripts);
	}
}

}

 /* namespace QLINK */
