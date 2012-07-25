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
#include "../stpl/stpl_unigrammar.h"
#include "../stpl/stpl_stream.h"

#include "../spec/default.h"

using namespace std;
using namespace stpl;
using namespace UNICODE;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " file" << std::endl;
		return -1;
	}

	FileStream<> file(argv[1]);
	//typedef Parser<DefaultDocument, ChineseGrammar<DefaultDocument> >	ChineseParser;
	DefaultChineseParser::string_type content(file.begin(), file.end());

	DefaultChineseParser parser(content.begin(), content.end());
	DefaultChineseParser::document_type& doc = parser.doc();
	DefaultChineseParser::document_type::entity_iterator it;

	parser.parse();

	for (it = doc.iter_begin(); it != doc.iter_end(); it++) {
		cout << (*it)->to_string() << endl;
	}
	return 0;
}
