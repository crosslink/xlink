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
#include <fstream>
#include <cassert>
#include "../stpl/stpl_stream.h"
#include "../stpl/lang/stpl_unicode.h"

using namespace stpl;
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		//std::cout << "Usage: test_unicde file" << std::endl;
		//return 0;

		char a[] = {'\303', '\274', '\0'};  //unicode character, ü
		//char b[] = {'\344', '\275', '\240', '\0'}; //unicode character, 你  E4 BD A0
		//char c[] = {'\345', '\245', '\275', '\0'}; //unicode character, 好

		char b[] = {0xE4, 0xBD, 0xA0, '\0'}; //unicode character, 你  E4 BD A0
		char c[] = {0xE5, 0xA5, 0xBD, '\0'}; //unicode character, 好

		string astr(a);
		string bstr(b);
		string cstr(c);

		cout << "a(" << astr << ") compare with b(" << bstr << "): " << astr.compare(bstr) << endl
			<< "b(" << bstr << ") compare with c(" << cstr << "): " << bstr.compare(cstr) << endl;

		int b_code = UNICODE::Utf8<string>::code(bstr);
		int c_code = UNICODE::Utf8<string>::code(cstr);

		cout << "b code: " << b_code << endl;
		cout << "c code: " << c_code << endl;

		string a_char("a");
		assert(UNICODE::Utf8<string>::code(a_char) == 'a');
		assert(b_code == 0x4f60);
		assert(c_code == 0x597d);

		string empty("");
		string ab = astr + bstr;
		string abc = ab + cstr;
		assert(UNICODE::Utf8<string>::size(ab) == 2);
		assert(UNICODE::Utf8<string>::size(abc) == 3);
		assert(UNICODE::Utf8<string>::size(empty) == 0);
		return 1;
	}
	/*
    char *fname;
    ifstream fin;

    fname = argv[1];
    fin.open(fname, ios::in|ios::binary);
    unsigned char code;
    while(!(fin.eof())) {
        fin.read((char *) &code, sizeof(code));
        std::cout << "Code: " << static_cast<int>(code) << std::endl;
    }
    */

	string file_name = argv[ 1 ];
	FileStream<> file_stream(file_name.c_str());

	FileStream<>::iterator it = file_stream.begin();
	while (it != file_stream.end()) {
		std::string temp_utf8 = UNICODE::Utf8<string, FileStream<>::iterator>::first_utf8_char(it);
		//std::cout << "unicode character (size: " << temp_utf8.length() << ") - " ;
		std::cout << temp_utf8 << std::endl;
		it += temp_utf8.length();
	}


	return 1;
}
