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
 * wikipedia.cpp
 *
 *  Created on: Oct 7, 2009
 *
 */

#include "wikipedia.h"
#include "webpage_retriever.h"

#include "string_utils.h"
#include "xml.h"

#include <iostream>

#include <stpl/stpl_stream.h>
#include <stpl/xml/stpl_xml.h>

#include <boost/regex.hpp>

using namespace QLINK;
using namespace std;
using namespace stpl;

wikipedia::wikipedia()
{

}

wikipedia::~wikipedia()
{
}

std::pair<std::string, std::string> wikipedia::process_title(std::string& orig, bool lowercase/*, bool english_only*/)
{
	std::string title("");
	std::string desc("");

//	if (orig.find("Homer Simpson") != string::npos)
//		cerr << "I got you" << endl;

	string::iterator it = orig.begin();
	while ((*it) == ' ')
		++it;

	for (; it != orig.end(); it++) {
		if ((*it) == '&') {
			title.push_back(' ');
			++it;
			while ((*it) != ';')
				it++;
			++it;

			if (it == orig.end())
				break;
		}
		if ((*it) == '(') {
			++it;
			while (it != orig.end() && (*it) != ')') {
				desc.push_back(*it);
				++it;
			}
			break;
		}

//		if (english_only && !isalnum(*it))
//			*it = ' ';
		title.push_back(lowercase ? tolower(*it) : *it);
	}
	string::size_type pos = title.find_last_not_of(" ");
	title.erase(pos + 1);
	trim_left(desc, " ");
	trim_right(desc, " ");
	return make_pair(title, desc);
}

std::string QLINK::wikipedia::get_article_abstract_by_id(std::string lang, std::string id) {
	webpage_retriever page_fetcher;
	string api_text;
	string page;

	stringstream url_for_wikipedia_article_by_id;
	url_for_wikipedia_article_by_id << "http://" << lang << ".wikipedia.org/w/api.php?action=parse&section=0&format=xml&pageid=" << id;
	api_text = page_fetcher.retrieve(url_for_wikipedia_article_by_id.str().c_str());

	typedef XML::XParser<string> 					xml_parser;
	typedef xml_parser::document_type::entity_type	  			node_type;
	typedef xml_parser::document_type::entity_iterator 		entity_iterator;
	typedef xml_parser::document_type::element_type			element_type;
	xml_parser parser(api_text.begin(), api_text.end());
	parser.parse();

	xml_parser::document_type &doc = parser.doc();

	entity_iterator	it;

	for (it = doc.iter_begin(); it != doc.iter_end(); ++it) {
		node_type *node = static_cast<node_type*>((*it));

		if (node->is_element()) {
			element_type *elem = static_cast<element_type *>(node);

			element_type *text = elem->find_child("text");
			if (text) {
				text->text(page);
				un_xmlify(page);
				bound_type bound = get_article_abstract(page);
				page = page.substr(bound.first, bound.second - bound.first);
			}
			else
				page = "<div>internal error</div>";
			break;
		}
	}
	return page;
}

std::pair<long, long> QLINK::wikipedia::get_article_abstract(
		std::string& page) {
	bound_type bound;
	bound.first = 0;
	bound.second = page.length();

	boost::match_results<std::string::const_iterator> what;
	boost::match_flag_type flags = boost::match_default;
	std::string::const_iterator s = page.begin();
	std::string::const_iterator e = page.end();
	static string p_tag_start = "<[\\s+]p[\\s+]>";
	static string p_tag_end = "<[\\s+]/[\\s+]p[\\s+]>";
	boost::regex s_re(p_tag_start);
	boost::regex e_re(p_tag_end);
	if (boost::regex_search(s, e, what, s_re, flags)){
//		std::cout << what.position() << std::endl;
//		std::string::difference_type l = what.length();
//		std::string::difference_type p = what.position();
//		s += p + l;

		bound.first = what.position();

		s += bound.first;
		if (boost::regex_search(s, e, what, e_re, flags)) {
			bound.second = what.position();
		}
	}
	else {
		const char *p_start = strstr(page.c_str(), "<p>");
		if (p_start) {
			const char *p_end = strstr(p_start, "</p>");
			bound.first = p_start - page.c_str();
			if (p_end)
				bound.second = p_end - page.c_str() + 4;
		}
	}
	return bound;
}
