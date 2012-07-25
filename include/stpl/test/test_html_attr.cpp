/******************************************************************************
 * This file is part of the Simple Text Processing Library(STPL).
 * (c) Copyright 2007-2008 TYONLINE TECHNOLOGY PTY. LTD.
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU LESSER GENERAL PUBLIC LICENSE, Version 3 as published by the Free Software
 * Foundation and appearing in the file LICENSE.LGPL included in the
 * packaging of this file.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 *******************************************************************************
 *
 * @author				Ling-Xiang(Eric) Tang 
 *
 *******************************************************************************/

#include <iostream>
#include <string>

#include "../utils/icstring.h"
#include "../stpl/stpl_stream.h"
#include "../stpl/html/stpl_html.h"

#include "../utils/charset_converter.h"

using namespace std;
using namespace stpl;

int main(int argc, char* argv[])
{	
	if (argc == 2) {
		string file_name = argv[ 1 ];
		FileStream<> file_stream(file_name.c_str());
		/*
		HTML::HtmlFile html_file(file_stream.begin(), file_stream.end());
		HTML::HtmlFileParser html_parser3(&html_file);
		html_parser3.parse();
		
		html_file.reset();
		while (html_file.more()) {
			HTML::HtmlFile::entity_iterator it = html_file.next();
			
			if ((*it)->type() == XML::ELEMENT) {
				typedef HTML::HtmlFileElementType Element;
				Element* elem_ptr = static_cast<Element*>(*it);
				typedef HTML::HtmlFileElementType::tree_type tree_type;
				tree_type tree;
				elem_ptr->traverse(tree);
			*/
		HTML::HParser<icstring, FileStream<>::iterator> parser(file_stream.begin(), file_stream.end());
		typedef HTML::HParser<icstring, FileStream<>::iterator>::element_type element_type;
		typedef HTML::HParser<icstring, FileStream<>::iterator>::tree_type tree_type;
		tree_type tree = parser.parse_tree();			
		tree_type::iterator	iner_it = tree.begin();
		for ( ; iner_it != tree.end(); ++iner_it) {
			if ((*iner_it)->is_element()) {
				element_type* elem_ptr = static_cast<element_type*>(*iner_it);
				if (elem_ptr->name() == "A") {
					cout << "found a link: " << endl;
					//elem_ptr->print_attributes();
					pair<bool, element_type::string_type> attr = 
							elem_ptr->attribute("Href1");
							//elem_ptr->attribute(element_type::string_type("hrEf"));
					if (attr.first) {
						std::string utf_link; 
						std::string orig_link(attr.second.c_str());
						if (stpl::CharsetConverter<std::string>::convert("gb2312", "UTF-8", orig_link, utf_link) == stpl::GOOD) {
							cout << "GB: " << orig_link << endl;
							cout << "UTF: " << utf_link << endl;
						}
						else
							cout << orig_link << endl;
					}
				} else if ( elem_ptr->name() == "meta") {
					elem_ptr->print_attributes();
					pair<bool, element_type::string_type> attr = 
							elem_ptr->attribute("content");
					
					cout << "content: " << attr.second.c_str() << endl;
					attr = 
							elem_ptr->attribute("name");
					
					cout << "name: " << attr.second.c_str() << endl;							
				}
			}
		}
				//break;
			//}
		//}		
	} else {
        std::cout
            << "Usage: on command the line, enter the path name of the html file, for example,"
            << std::endl
            << '\t'
            << argv[ 0 ]
            << " example.html"
            << std::endl
            ;

        return 1;
	}
	
	return 0;		
}
