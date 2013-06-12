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
 *      Author: monfee
 */

#include "wikipedia.h"
#include "string_utils.h"

#include <iostream>

using namespace QLINK;
using namespace std;

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
