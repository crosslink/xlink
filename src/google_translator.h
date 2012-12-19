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

//namespace QLINK {

	class google_translator : public pattern_singleton<google_translator>
	{
	public:
		enum {DO_NOTHING, LOAD_KEY};

		static const char *GOOGLE_TRANSLATE_URL_TEMPLATE;
		static const char *LANGUAGE_PAIR_EN_CS;
		static const char *LANGUAGE_PAIR_EN_CT;

		static const char *TEST_STRING_EN;
		static const char *TEST_STRING_ZH;

		static const char *GOOGLE_TRANSLATE_API_KEY_FILE;

		static const int KEY_UNKNOWN = -1;
		static const int KEY_INVALID = 99;
		static const int KEY_VALID = 1;
		static const int KEY_LOADED = 0;

		static const int RESULT_CODE_SUCCESS = 0;
		static const int RESULT_CODE_ERROR = -1;
//		static const int RESULT_CODE_ERROR = -1; other errors types

	protected:
		static std::string api_key;
		static int key_status;
		static std::string api_key_file;

		static std::string query_template;
		static std::string query_lang_pair_template;

		static std::string source_lang_var;
		static std::string target_lang_var;

		static std::string source_lang;
		static std::string target_lang;

		static bool to_test_key;

		std::string trans;

		bool initialized;

	public:
		google_translator();
		virtual ~google_translator();

		const char *translate(const char *text, long length = -1);
		static bool has_valid_key();

		virtual std::string get_translation(const char *content);

		google_translator& get_instance();
		google_translator& get_instance(int do_what);

		static void set_lang_pair(const char *langpair);
		static void set_to_test_key(bool value) { to_test_key = value; }
		static void set_api_key(const char *key) { api_key = key; }

		bool test_key();

		bool is_initialized() const;
		void set_initialized(bool initialized);

		virtual void initialize(int do_what = DO_NOTHING);

	protected:

		void append_text(std::string& url, const char *text, long length = 0);
		void append_lp(std::string& url, const char *language_pair);

		static void add_lang_options(std::string& url);

		void add_text_option(std::string& url, const char *text, long length = 0);

//	private:
		void init(int do_what = DO_NOTHING);
		void init_once(int do_what = DO_NOTHING);
		virtual void set_key();

	};

//}

#endif /* GOOGLE_TRANSLATOR_H_ */
