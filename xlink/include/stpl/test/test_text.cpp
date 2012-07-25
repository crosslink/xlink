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
#include "../stpl/stpl_doc.h"
#include "../spec/text.h"
#include "../stpl/xml/stpl_xml.h"

using namespace std;
using namespace stpl;
using namespace TEXT;

int main(int argc, char* argv[])
{
	string txt;

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

	txt = argv[ 1 ];
#endif

	txt = "mahdi addf ** @#43 sdf 8*&^^ dfdd adf ksad   w() wef23fdf  dkfw99 !!";
	//string txt = ") wef23fdf  dkfw99 !!";

	//typedef Word<std::string, std::string::iterator> Word;
	//typedef PlainDocument<Word> PlainText;
	//PlainTextDocument txt_doc(txt.begin(), txt.end());
	//PlainTextGrammar<PlainText>
	PlainTextParser	txt_parser(txt.begin(), txt.end());
	PlainTextParser::document_type& txt_doc = txt_parser.doc();

	txt_parser.parse();

	txt_doc.reset();
	while (txt_doc.more()) {
		(*(txt_doc.next()))->print();
		cout << endl;
	}

}
