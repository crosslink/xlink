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
#include "../spec/property.h"
#include "../stpl/stpl_stream.h"

using namespace std;
using namespace stpl;

int main(int argc, char* argv[])
{
	if (argc == 2) {
		string file_name = argv[ 1 ];
		PropertiesFile file(file_name.c_str());
		PropertiesFileParser properties_parser3(&file);
		PropertiesFileParser::document_type& properties_file = properties_parser3.doc();
		properties_parser3.parse();

		PropertiesFileParser::document_type::entity_iterator it;
		for (it = properties_file.iter_begin(); it != properties_file.iter_end(); ++it) {
			cout << "Read (";
			(*it)->print();
			cout << ")" << endl;
			cout << (*it)->name()
			     << ":="
			     << (*it)->value()
			     << endl;
		}
		/*
		properties_file.reset();
		while (properties_file.more()) {
			PropertiesFile::entity_iterator it = properties_file.next();
			cout << "Read (";
			(*it)->print();
			cout << ")" << endl;
			cout << (*it)->name()
			     << ":="
			     << (*it)->value()
			     << endl;
		}
		*/
	} else {
		std::string properties_code("a=1 b=\"l ove you\" c=3 d=6.5 e=true");
		//std::string properties_code("e=true");
		PropertiesParser properties_parser(properties_code.begin(), properties_code.end());
		Properties&	properties_doc = properties_parser.doc();
		properties_parser.parse();

		properties_doc.reset();
		while (properties_doc.more()) {
			Properties::entity_iterator it = properties_doc.next();
			cout << "Read (";
			(*it)->print();
			cout << ")" << endl;
			cout << (*it)->name()
			     << ":="
			     << (*it)->value()
			     << endl;
		}
	}

	return 0;
}
