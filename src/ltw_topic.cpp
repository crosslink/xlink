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
 * ltw_topic.cpp
 *
 *  Created on: Sep 9, 2009
 *      Author: monfee
 */

#include "ltw_topic.h"
#include "xml2txt.h"
#include "corpus_txt.h"
#include "sys_file.h"
#include "ant_link_parts.h"
#include "string_utils.h"

#include <stdlib.h>

using namespace QLINK;

ltw_topic::ltw_topic(const char *file) : topic(file), ltw_task_(NULL)
{
	text_of_xml_ = NULL;
}

ltw_topic::~ltw_topic()
{
	if (text_of_xml_)
		delete [] text_of_xml_;
		//free(text_of_xml_);
}

const char *ltw_topic::get_text()
{
	if (!text_of_xml_)
		xml_to_text();
	return text_of_xml_; /*? text_of_xml_ : content_;*/
}

void ltw_topic::xml_to_text()
{
	//text_of_xml_ = xml2txt::instance().convert(content_);
	//text_of_xml_ = sys_file::read_entire_file(corpus_txt::instance().id2docpath(id_).c_str());
	if (id_ > 0) {
		text_of_xml_ = xml2txt::instance().gettext(filename_, NULL, content_);
		//text_of_xml_ = xml2txt::instance().gettext(id_, content_);
	}
//	else
//		text_of_xml_ = xml2txt::instance().gettearatext(name_, content_);

	if (!text_of_xml_) {
		//text_of_xml_ = new char[strlen(content_) + 1];
		//strcpy(text_of_xml_, content_);
		//string_clean(text_of_xml_, 0, 0);
		text_of_xml_ = xml2txt::instance().clean_tags(content_, 0);
	}

	/*
	 *
	 *
	 */
	std::string text_file = number_to_string(id_) + ".txt";
	sys_file::write(text_of_xml_, text_file.c_str());
}

long QLINK::ltw_topic::get_term_len(long  offset, char *term, bool is_cjk_lang)
{
	const char *start, *end;
	char *where_to = term;
	long term_len = 0, char_len;
	long target_term_len = strlen(term);

	char buffer[1024];

	end = start = content_ + offset;

	while (*where_to != '\0') {

//		strncpy(buffer, start, char_len);
		char_len = language::utf8_bytes(where_to);
		if (*where_to == *end) {
			end += char_len;
			where_to += char_len;
		}
		else {
			if (*end == ' ') {
				if (is_cjk_lang) {
					end = start;
					break;
				}
				else
					while (*end == ' ')
						++end;
			}
//			else {
//				if (isspace(*end)) {
//	//				if (is_cjk_lang) {
//						end = start;
//						break;
//	//				}
//				}
//			}
			if (*end == '<') {
				while (*end != '\0' && *end != '>')
					++end;
				if (*end != '\0')
					++end;
			}

			if (*end == ' ') {
				if (is_cjk_lang) {
					end = start;
					break;
				}
				else
					while (*end == ' ')
						++end;
			}

			if (*where_to != *end) {
				end = start;
				break;
			}
		}
//		if (term_len >= target_term_len)
//			break;
	}
	term_len =  end - start;
	return term_len;
}
