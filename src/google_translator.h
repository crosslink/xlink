/*
 * google_translator.h
 *
 *  Created on: Jan 6, 2010
 *      Author: monfee
 */

#ifndef GOOGLE_TRANSLATOR_H_
#define GOOGLE_TRANSLATOR_H_

#include <string>
#include "pattern_singleton.h"

namespace QLINK {

	class google_translator : public pattern_singleton<google_translator>
	{
	public:
		static const char *GOOGLE_TRANSLATE_URL_TEMPLATE;
		static const char *LANGUAGE_PAIR_EN_CS;
		static const char *LANGUAGE_PAIR_EN_CT;

	public:
		google_translator();
		virtual ~google_translator();

		std::string translate(const char *text, const char *language_pair);

	private:
		std::string get_translation(const char *content);

		void append_text(std::string& url, const char *text);
		void append_lp(std::string& url, const char *language_pair);

		void add_lang_options(std::string& url, const char *language_pair);
		void add_text_option(std::string& url, const char *text);
	};

}

#endif /* GOOGLE_TRANSLATOR_H_ */
