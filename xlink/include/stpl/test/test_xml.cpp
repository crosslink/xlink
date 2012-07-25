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

//#include "../stpl/stpl_keyword.h"
//#include "../stpl/xml/stpl_xml_parser.h"
#include "../stpl/stpl_stream.h"
//#include "../stpl/stpl_doc.h"
//#include "../stpl/stpl_text.h"
#include "../stpl/xml/stpl_xml.h"

using namespace std;
using namespace stpl;

int main(int argc, char* argv[])
{
	string str;

#ifdef GET_ARG1
    if ( argc == 1 ) {
        std::cout
            << "Usage: on command the line, enter some words to count, for example,"
            << std::endl
            << '\t'
            << argv[ 0 ]
            << " abc def ghi"
            << std::endl
            ;

        return 1;
    }

	str = argv[ 1 ];
#endif

	// xml parser

	if (argc < 2) {
		str = "<xml> <child1/> <child2>wolrd<gradchild>nihao</gradchild></child2>hello \n</xml>";
	} else {
		FileStream<string, char *> fs(argv[1]);
		str = string(fs.begin(), fs.end());
	}

	XML::XParser<string> parser(str.begin(), str.end());
	parser.parse();
	//XML::XParser<string>::tree_type dom = parser.parse_tree();

	std::string text;
	std::map<std::string, bool> nm;
	nm.insert(make_pair(string("languagelink"), false));
	nm.insert(make_pair(string("TEXT"), true));
	parser.root()->all_text(text, nm);
	cout << text;

	//parser.root()->print();


	//XML::XmlParser<> xml_parser(xml_string.begin(), xml_string.end());
	//xml_parser.parse();
	//xml_parser.print();

	//char* chars = "<xml2> <child1/> <child2>wolrd<gradchild>nihao</gradchild></child2>hello \n</xml2>";
	//XML::XmlParser<std::string, char*> xml_parser2(chars, chars + strlen(chars));
	//xml_parser2.parse();
	//xml_parser2.print();



}
