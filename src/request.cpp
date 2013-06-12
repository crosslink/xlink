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
 *      Author: monfee
 */

#include "request.h"

#include <string>
#include <stpl/stpl_stream.h>
#include <stpl/xml/stpl_xml.h>

using namespace std;
using namespace stpl;

namespace QLINK {

request::request() : wikified_(false), last_request_time_(time(0)) {

}

request::request(const request& rsq) {
	this->last_request_time_ = rsq.get_last_request_time();
	this->page_ = rsq.get_page();
	this->wikified_ = rsq.is_wikified();
}

request::~request() {

}

void request::apply_links(const std::string& links_xml) {
	typedef XML::XParser<string, string::const_iterator> xml_parser;
	typedef 	xml_parser::document_type::entity_type	  node_type;
	xml_parser parser(links_xml.begin(), links_xml.end());
	parser.parse();

	xml_parser::document_type &doc = parser.doc();

	xml_parser::document_type::entity_iterator	it;

	for (it = doc.iter_begin(); it != doc.iter_end(); ++it) {
		node_type *node = static_cast<node_type*>((*it));

		if (node->is_element())
			node->print();
	}
}

} /* namespace QLINK */
