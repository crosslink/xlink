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
 * translation.cpp
 *
 *  Created on: Apr 18, 2011
 *
 */

#include "translation.h"
#include "sys_file.h"
#include "run_config.h"
#include "google_translator.h"

#include <fstream>
#include <utility>
#include <sstream>
#include <iostream>

using namespace QLINK;
using namespace std;

const char *translation::CACHE_FOLDER = ".translation_cache";

translation::translation()
{
	if (sys_file::exist(CACHE_FOLDER)) {
		ifstream myfile (CACHE_FOLDER);

		if (myfile.is_open()) {
			while (! myfile.eof()) {
				string line;
				getline (myfile, line);
				string::size_type pos = line.find_first_of(':');
				if (pos != string::npos) {
					translations_[line.substr(0, pos)] = line.substr(pos + 1);
				}
			}
		}
	}

	if (run_config::instance().get_value("create_translation_cache").length() > 0)
		cache_it_ = true;
}

translation::~translation()
{
	if (cache_it_) {
		ofstream out(CACHE_FOLDER);
		map<std::string, std::string>::iterator it = translations_.begin();
		while (it != translations_.end()) {
			out << it->first << ":" << it->second << endl;
			++it;
		}
		out.close();
	}
}


std::string translation::translate(const char *word, const char *language_pair)
{

	map<std::string, std::string>::iterator it = translations_.find(word);
	if (it != translations_.end())
		return it->second;

	std::string result = google_translator::instance().translate(word);
	translations_[word] = result;

	return result;
}
