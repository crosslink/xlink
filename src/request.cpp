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
	wikification::linkify(links_xml, page_, wikified_page_);
	cerr << endl << "finished wikify page" << endl;
}

} /* namespace QLINK */
