/*
 * google_translator.cpp
 *
 *  Created on: Jan 6, 2010
 *      Author: monfee
 */

#include "google_translator.h"
#include "webpage_retriever.h"
#include "string_utils.h"
#include "sys_file.h"
#include "urlcode.h"
#include "database_mysql.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <stpl/stpl_parser.h>
#include <stpl/stpl_property.h>

using namespace std;

//	const char *google_translator::GOOGLE_TRANSLATE_URL_TEMPLATE = "http://translate.google.com/?oe=utf8"; //&langpair=en|zh&text=dahuangshan
const char *google_translator::GOOGLE_TRANSLATE_URL_TEMPLATE = "https://www.googleapis.com/language/translate/v2?key=%s";
const char *google_translator::LANGUAGE_PAIR_EN_CT = "en:zh-TW";
const char *google_translator::LANGUAGE_PAIR_EN_CS = "en:zh-CN";

const char *google_translator::TEST_STRING_EN = "I";
const char *google_translator::TEST_STRING_ZH = "\346\210\221"; // chinese character for "I"

std::string google_translator::api_key("");
std::string google_translator::query_template("");
std::string google_translator::query_lang_pair_template("");

std::string google_translator::api_key_file("");
std::string google_translator::source_lang_var("");
std::string google_translator::target_lang_var("");

std::string google_translator::source_lang("");
std::string google_translator::target_lang("");

const char *google_translator::GOOGLE_TRANSLATE_API_KEY_FILE = "key.txt";

int google_translator::key_status =  google_translator::KEY_UNKNOWN;
bool google_translator::to_test_key = false;

google_translator::google_translator() : initialized(false)
{

}

google_translator::~google_translator()
{

}

void google_translator::init_once(int do_what) {
	if (do_what == LOAD_KEY) {
		if (key_status == KEY_UNKNOWN) {
			if (sys_file::exist(api_key_file.c_str())) {
				const char *key_text = NULL;
				key_text = sys_file::read_entire_file(api_key_file.c_str());
				if (key_text != NULL)
					api_key = key_text;

				delete [] key_text;
			}
			else {
				api_key = database_mysql::instance().get_google_translate_key().c_str();
			}

			if (api_key.length() > 0) {
				this->set_key();
				if (to_test_key)
					test_key();
			}
			else {
				cerr << "No key found!" << endl;
				exit(-3);
	//			key_status = KEY_INVALID;
			}
		}
	}
	this->initialized = true;
}

google_translator& google_translator::get_instance(int do_what) {
	google_translator& instance = get_instance();
	if (!instance.is_initialized())
		instance.initialize(do_what);
	return instance;
}

bool google_translator::is_initialized() const {
	return initialized;
}

void google_translator::set_initialized(bool initialized) {
	this->initialized = initialized;
}

void google_translator::initialize(int do_what) {
	init(do_what);
}

void google_translator::set_key()
{
	char buf[1024];
	int len = api_key.length() + strlen(GOOGLE_TRANSLATE_URL_TEMPLATE);
	sprintf(buf, (char *)GOOGLE_TRANSLATE_URL_TEMPLATE, api_key.c_str());
	buf[len] = '\0';
	query_template = buf;
}

google_translator & google_translator::get_instance()
{
	static google_translator instance;
	return instance;
}

void google_translator::init(int do_what)
{
	if (key_status <= KEY_UNKNOWN) {
		api_key_file = GOOGLE_TRANSLATE_API_KEY_FILE;
		source_lang_var = "source";
		target_lang_var = "target";
		init_once(do_what);
	}
}

void google_translator::set_lang_pair(const char* language_pair) {
	const char *pos = strchr(language_pair, ':');
	source_lang = string(language_pair, pos);
	target_lang = string(pos + 1);
	query_lang_pair_template.clear();
	add_lang_options(query_lang_pair_template);
}

bool google_translator::test_key() {
	string old_source_lang = source_lang;
	string old_target_lang = target_lang;
	set_lang_pair(LANGUAGE_PAIR_EN_CS);
	string result = translate(TEST_STRING_EN);

	source_lang = old_source_lang;
	target_lang = old_target_lang;

	bool has_valid_key = (result == TEST_STRING_ZH);
	if (has_valid_key)
		key_status = KEY_VALID;
	else
		key_status = KEY_INVALID;

	switch (key_status) {
	default:
	case KEY_UNKNOWN:
		std::cerr << "Unknown key loaded: " << api_key << std::endl;
		exit(-1);
	case KEY_INVALID:
		std::cerr << "Invalid Google Translate API key: " << api_key << std::endl;
		exit(-1);
	case KEY_VALID:
		std::cerr << "Google Translate API key: " << api_key << endl << " has been successfully verified. " << std::endl;
		break;
	}

	return has_valid_key;
}

bool google_translator::has_valid_key() {
	return key_status == KEY_VALID;
}

const char *google_translator::translate(const char *text, long length)
{
	int response_code = 0;
	string url(query_template);
//		append_lp(url, language_pair);
//		append_text(url, text);
	add_text_option(url, text, length);

	url.append(query_lang_pair_template);

//	add_lang_options(url, language_pair);
	const char *content = webpage_retriever::instance().retrieve(url.c_str(), &response_code);
//	response_code = webpage_retriever::instance().get_response_code();
	if (response_code == 200) {
		trans = get_translation(content);
		return trans.c_str();
	}
	else  {
		cerr << content << endl;
		if (response_code == 401){
			exit(-4);
		}
		else{
			cerr << endl << "HTTP REQUEST: " << endl << url << endl;
		}
	}
	return NULL;
}

std::string google_translator::get_translation(const char *content)
{
	const char *start, *end;
	static const char *TEXTAREA_TAG = "translatedText";
	string gtrans;

	start = strstr(content, TEXTAREA_TAG);
	if (start != NULL) {
		start += strlen(TEXTAREA_TAG);
		start = strchr(start, ':');

		start = strchr(start, '"');
		++start;
		end =  strchr(start, '"');
		gtrans = string(start, end);
	}
	return gtrans;
}

//	std::string google_translator::get_translation(const char *content)
//	{
//		const char *start = content, *end;
//		static const char *TEXTAREA_TAG = "<textarea";
//		string gtrans;
//
//		while ((start = strstr(start, TEXTAREA_TAG)) != NULL) {
//			start += strlen(TEXTAREA_TAG);
//			if (!(end = strchr(start, '>')))
//				break;
//
//			stpl::GeneralParser<stpl::Property<string, const char *> > property_parser(start, end);
//			property_parser.parse();
//			stpl::Property<string, const char *> *property;
//			while ((property = property_parser.get_next_entity()) != NULL)
//				if (property->name() == "name") {
//					string value = property->value();
//					if (value == "utrans") {
//						const char *trans_start, *trans_end;
//						++end;
//						trans_start = end;
//						trans_end = strchr(trans_start, '<');
//						return string(trans_start, trans_end);
//					}
//				}
//		}
//		return "";
//	}

void google_translator::append_text(std::string& url, const char *text, long length)
{
	url.append("&text=");
	long count = 0;
	while (*text != '\0' && count < length) {
		if (*text == ' ')
			url.append("%20");
		else if (*text == ',')
			url.append("%2C");
		else if (*text == '\'')
			url.append("%27");
		else if (isalnum(*text))
			url.push_back(*text);
		else
			url.append("%" + byte_to_string(*text, 16));

		text += (++count);
	}
	//url.append(text);
}

void google_translator::append_lp(std::string& url, const char *language_pair)
{
	url.append("&langpair=");
	url.append(language_pair);
}

void google_translator::add_lang_options(std::string& url)
{
//	const char *pos = strchr(language_pair, ':');
//	string source_lang(language_pair, pos);
//	string target_lang(pos + 1);
	url.append("&");
	url.append(source_lang_var);
	url.append("=");
	url.append(source_lang);
	url.append("&");
	url.append(target_lang_var);
	url.append("=");
	url.append(target_lang);
}

void google_translator::add_text_option(std::string& url, const char *text, long length)
{
	char *copy = strdup(text);
	char *encoded_text = url_encode(copy);
	url.append("&q=");
	if (length > -1)
		url.append(encoded_text, length);
	else
		url.append(encoded_text);
	free(encoded_text);
	free(copy);
}

