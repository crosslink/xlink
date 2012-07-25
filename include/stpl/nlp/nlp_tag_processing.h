/******************************************************************************
 * This file is part of the Simple Text Processing Library(STPL).
 * (c) Copyright 2007-2010 TYONLINE TECHNOLOGY PTY. LTD.
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

#ifndef NLP_TAG_PROCESSING_H_
#define NLP_TAG_PROCESSING_H_

#include <utility>
#include <string>
#include <vector>

#include <string.h>
#include "nlp_tag.h"

namespace stpl
{
	namespace nlp
	{
		enum { STANDFORD_TAGGER };

		typedef std::pair<std::string, std::string>	word_tag_pair_type;

		template <int TAGGER_TYPE = STANDFORD_TAGGER>
		inline word_tag_pair_type get_word_and_tag(const char *tagged_word) {
			std::string word("");
			std::string tag("");

			switch (TAGGER_TYPE) {
				case STANDFORD_TAGGER:
				default:
					const char *underscore = strchr(tagged_word, '_');

					if (underscore != NULL) {
						word = std::string(tagged_word, underscore);
						++underscore;
						tag = std::string(underscore);
					}
					else
						word = std::string(tagged_word);
					break;
			}
			return make_pair(word, tag);
		}

		typedef std::vector<word_tag_pair_type > tagged_word_array_type;

		template <int TAGGER_TYPE = STANDFORD_TAGGER>
		inline tagged_word_array_type convert_to_word_tag_array(const char *tagged_version) {
			tagged_word_array_type wt_array;
			const char *start = NULL, *end = NULL;
			start = end = tagged_version;
			while (*start != '\0') {
				while (isspace(*start))
					++start;

				if (*start == '\0')
					break;

				end = start;
				while (*end != '\0' && *end != '_')
					++end;
				while (*end != '\0' && !isspace(*end))
					++end;

				std::string word_with_tag(start, end);
				word_tag_pair_type wt = get_word_and_tag<TAGGER_TYPE>(word_with_tag.c_str());
				if (strlen(pos_tag_map[wt.second]) > 0)
					wt.first = pos_tag_map[wt.second];

				wt_array.push_back(wt);

				if (*end == '\0')
					break;

				start = end;
			}
			return wt_array;
		}

		template <int TAGGER_TYPE = STANDFORD_TAGGER>
		inline std::string restore_tagged_version(const char *tagged_version) {
			std::string original;
			tagged_word_array_type wt_array = convert_to_word_tag_array(tagged_version);

			for (int i = 0; i < wt_array.size(); i++) {
				if (i > 0 && stpl::nlp::pos_tag_table[wt_array[i].second] != stpl::nlp::POS)
					original.append(" ");
				original.append(wt_array[i].first);
			}
			return original;
		}
	}
}
#endif /* NLP_TAG_PROCESSING_H_ */
