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

#include "../stpl/misc/stpl_trec.h"
#include "../spec/default.h"
#include "../stpl/stpl_stream.h"

using namespace std;
using namespace stpl;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " file" << std::endl;
		return -1;
	}

	FileStream<> file_stream(argv[1]);
	//FileStream<> file_stream("/home/eric/src/c++/parsers/stpl/moby.txt");
	//typedef	TREC::TrecDocument<XML::Element<std::string, char*> >	TrecDocType;
	//TREC::TrecDocParser<TrecDocType> parser(file_stream.begin(), file_stream.end());
	//typedef TrecDocType::string_type StringType;
	TREC::DefaultTrecDocParser::string_type content(file_stream.begin(), file_stream.end());
	TREC::DefaultTrecDocParser parser(content.begin(), content.end());
	TREC::DefaultTrecDocParser::document_type& doc = parser.doc();
	parser.parse();

	TREC::DefaultTrecDocParser::document_type::entity_iterator iter;
	typedef TREC::DefaultTrecDocParser::string_type	string_type;
	typedef	TREC::DefaultTrecDocGrammar::node_type	node_type;
	for (iter = doc.iter_begin(); iter != doc.iter_end(); iter++) {
		node_type* node_ptr = static_cast<node_type*>((*iter));

		/** getting all the text node */
		//cout << node_ptr->all_text();

		/// getting some of the text we want
		std::map<string_type, bool> nm;
		nm.insert(make_pair(string_type("TEXT"), true));
		string_type text;
		node_ptr->all_text(text, nm);
		cout << text;

		//PlainTextScanner<StringType, StringType::iterator> text_scanner(text.begin(), text.end());
		//while(text_scanner.more()) {
		//	(*text_scanner.next())->print();
		//	cout << endl;
		//}
		cout << endl;
		break;
	}
}
