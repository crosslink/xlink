/*
 * google_research_translator.cpp
 *
 *  Created on: Apr 17, 2012
 *      Author: monfee
 */

#include "google_research_translator.h"
#include "webpage_retriever.h"

#include <stdio.h>
#include <stdlib.h>

#include <string>

using namespace std;

const char *google_research_translator::GOOGLE_TRANSLATE_RESEARCH_URL_TEMPLATE = "http://translate.google.com/researchapi/translate?";
const char *google_research_translator::GOOGLE_TRANSLATE_RESEARCH_API_KEY_FILE = "auth_key.txt";
const char *google_research_translator::GOOGLE_TRANSLATE_RESEARCH_AUTH_HEADER = "Authorization: GoogleLogin auth=";

google_research_translator::google_research_translator() {

}

google_research_translator::~google_research_translator() {

}


google_research_translator& google_research_translator::get_instance()
{
	static google_research_translator instance;
	instance.init();
	return instance;
}

void google_research_translator::init(int do_what)
{
	if (key_status <= KEY_UNKNOWN) {
		api_key_file = GOOGLE_TRANSLATE_RESEARCH_API_KEY_FILE;
		source_lang_var = "sl";
		target_lang_var = "tl";
		init_once(do_what);
	}
}

void google_research_translator::initialize(int do_what) {
	init(do_what);
}

void google_research_translator::set_key()
{
//	int len = api_key.length() + strlen(GOOGLE_TRANSLATE_RESEARCH_AUTH_HEADER);
//	char temp = new char[len + 1];
//	sprintf(temp, (char *)GOOGLE_TRANSLATE_URL_TEMPLATE, api_key.c_str());
//	temp[len] = '\0';
	query_template = GOOGLE_TRANSLATE_RESEARCH_URL_TEMPLATE;
	string header = string(GOOGLE_TRANSLATE_RESEARCH_AUTH_HEADER) + string(api_key);
	webpage_retriever::instance().add_header(header.c_str());
//	delete temp;
}

std::string google_research_translator::get_translation(const char *content)
{
	const char *start, *end;
	int len = strlen(content);

	static const char *ENTRY_TAG = "<entry>";
	static const char *TRANSLATION_TAG = "<gt:translation";
	string gtrans;

	start = strstr(content, ENTRY_TAG);
	if (start != NULL) {
		start = strstr(start, TRANSLATION_TAG);
		if (start != NULL) {
			start += strlen(TRANSLATION_TAG);
			start = strchr(start, '>');

			if (start != NULL && (start - content) < len) {
	//			start = strchr(start, ':');
	//
	//			start = strchr(start, '"');
				++start;
				end = strchr(start, '<');
				if (end != NULL && (end - content) < len) {
	//				end =  strchr(start, '"');
					gtrans = string(start, end);
				}
			}
		}
	}
	return gtrans;
}





