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

#ifndef NLP_TAGS_H_
#define NLP_TAGS_H_

#include <map>

namespace stpl
{
	namespace nlp
	{
		/*
		 * The POS tags are defined in http://bioie.ldc.upenn.edu/wiki/index.php/POS_tags
		 */
		enum {
			NONE = -1,
			DOLLAR = 0,
			PERIOD,
			COMMA,
			COLON,
			LEFT_QUOTATION,
			RIGHT_QUOTATION,
			LEFT_BRACKET,
			RIGHT_BRACKET,
			AFX,
			CC,
			CD,
			DT,
			EX,
			FW,
			HYPH,
			IN,
			JJ,
			JJR,
			JJS,
			LS,
			MD,
			NN,
			NNP,
			NNPS,
			NNS,
			PDT,
			POS,
			PRP,
			PRPDOLLAR,
			RB,
			RBR,
			RBS,
			RP,
			SYM,
			TO,
			token,
			UH,
			VB,
			VBD,
			VBG,
			VBN,
			VBP,
			VBZ,
			WDT,
			WP,
			WPDOLLAR,
			WRB
		};

		//extern	"C" {
	//	extern	const char **pos_tags;
	//	extern	const char **pos_tags_real;
		const char *pos_tags[] = {
				"$",
				".",
				",",
				":",
				"``",
				"''",
				"-LRB-",
				"-RRB-",
				"AFX",
				"CC",
				"CD",
				"DT",
				"EX",
				"FW",
				"HYPH",
				"IN",
				"JJ",
				"JJR",
				"JJS",
				"LS",
				"MD",
				"NN",
				"NNP",
				"NNPS",
				"NNS",
				"PDT",
				"POS",
				"PRP",
				"PRP$",
				"RB",
				"RBR",
				"RBS",
				"RP",
				"SYM",
				"TO",
				"token",
				"UH",
				"VB",
				"VBD",
				"VBG",
				"VBN",
				"VBP",
				"VBZ",
				"WDT",
				"WP",
				"WP$",
				"WRB"
		};

		const char *pos_tags_real[] = {
				"",
				"",
				"",
				"",
				"\"",
				"\"",
				"(",
				")",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				"",
				""
		};
		//}
		extern	std::map<std::string, const char *> pos_tag_map;
		extern	std::map<std::string, int> pos_tag_table;
	}

}
#endif /* NLP_TAGS_H_ */
