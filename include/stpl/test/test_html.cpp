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

#include "../stpl/stpl_scanner.h"
#include "../stpl/stpl_stream.h"
#include "../stpl/html/stpl_html.h"

using namespace std;
using namespace stpl;

int main(int argc, char* argv[])
{	
	if (argc == 2) {
		string file_name = argv[ 1 ];
		FileStream<> file_stream(file_name.c_str());
		HTML::HtmlFileParser html_parser3(file_stream.begin(), file_stream.end());
		HTML::HtmlFile html_file = html_parser3.doc();		
		
		html_parser3.parse();
		
		
		html_file.reset();
		while (html_file.more()) {
			HTML::HtmlFile::entity_iterator it = html_file.next();
			
			if ((*it)->type() == XML::ELEMENT) {
				HTML::HtmlFileElementType* elem_ptr = static_cast<HTML::HtmlFileElementType*>(*it);
				elem_ptr->print();
			}
			else
				(*it)->print();
			cout << endl;
		}		
		
	} else {
		icstring html_code("<!DOCTYPE html public><html></html>");
		HTML::HtmlParser html_parser(html_code.begin(), html_code.end());
		HTML::HtmlDocument	html_doc = html_parser.doc();		
		html_parser.parse();
		
		html_doc.reset();
		while (html_doc.more()) {
			HTML::HtmlDocument::entity_iterator it = html_doc.next();
			
			if ((*it)->type() == XML::ELEMENT) {
				HTML::HtmlElementType* elem_ptr = static_cast<HTML::HtmlElementType*>(*it);
				elem_ptr->print();
			}
			else
				(*it)->print();
			cout << endl;
		}		
	}
	
	return 0;		
}
