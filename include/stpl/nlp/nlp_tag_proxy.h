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

#ifndef NLP_TAG_MAP_H_
#define NLP_TAG_MAP_H_

#include <map>

namespace stpl
{
	namespace nlp
	{
		std::map<std::string, const char *> pos_tag_map;
		std::map<std::string, int> pos_tag_table;

		class nlp_tag_proxy {
		public:
			nlp_tag_proxy() {
				pos_tag_map[pos_tags[DOLLAR]] = pos_tags_real[DOLLAR];
				pos_tag_map[pos_tags[PERIOD]] = pos_tags_real[PERIOD];
				pos_tag_map[pos_tags[COMMA]] = pos_tags_real[COMMA];
				pos_tag_map[pos_tags[COLON]] = pos_tags_real[COLON];
				pos_tag_map[pos_tags[LEFT_QUOTATION]] = pos_tags_real[LEFT_QUOTATION];
				pos_tag_map[pos_tags[RIGHT_QUOTATION]] = pos_tags_real[RIGHT_QUOTATION];
				pos_tag_map[pos_tags[LEFT_BRACKET]] = pos_tags_real[LEFT_BRACKET];
				pos_tag_map[pos_tags[RIGHT_BRACKET]] = pos_tags_real[RIGHT_BRACKET];
				pos_tag_map[pos_tags[AFX]] = pos_tags_real[AFX];
				pos_tag_map[pos_tags[CC]] = pos_tags_real[CC];
				pos_tag_map[pos_tags[CD]] = pos_tags_real[CD];
				pos_tag_map[pos_tags[DT]] = pos_tags_real[DT];
				pos_tag_map[pos_tags[EX]] = pos_tags_real[EX];
				pos_tag_map[pos_tags[FW]] = pos_tags_real[FW];
				pos_tag_map[pos_tags[HYPH]] = pos_tags_real[HYPH];
				pos_tag_map[pos_tags[IN]] = pos_tags_real[IN];
				pos_tag_map[pos_tags[JJ]] = pos_tags_real[JJ];
				pos_tag_map[pos_tags[JJR]] = pos_tags_real[JJR];
				pos_tag_map[pos_tags[JJS]] = pos_tags_real[JJS];
				pos_tag_map[pos_tags[LS]] = pos_tags_real[LS];
				pos_tag_map[pos_tags[MD]] = pos_tags_real[MD];
				pos_tag_map[pos_tags[NN]] = pos_tags_real[NN];
				pos_tag_map[pos_tags[NNP]] = pos_tags_real[NNP];
				pos_tag_map[pos_tags[NNPS]] = pos_tags_real[NNPS];
				pos_tag_map[pos_tags[NNS]] = pos_tags_real[NNS];
				pos_tag_map[pos_tags[PDT]] = pos_tags_real[PDT];
				pos_tag_map[pos_tags[POS]] = pos_tags_real[POS];
				pos_tag_map[pos_tags[PRP]] = pos_tags_real[PRP];
				pos_tag_map[pos_tags[PRPDOLLAR]] = pos_tags_real[PRPDOLLAR];
				pos_tag_map[pos_tags[RB]] = pos_tags_real[RB];
				pos_tag_map[pos_tags[RBR]] = pos_tags_real[RBR];
				pos_tag_map[pos_tags[RBS]] = pos_tags_real[RBS];
				pos_tag_map[pos_tags[RP]] = pos_tags_real[RP];
				pos_tag_map[pos_tags[SYM]] = pos_tags_real[SYM];
				pos_tag_map[pos_tags[TO]] = pos_tags_real[TO];
				pos_tag_map[pos_tags[token]] = pos_tags_real[token];
				pos_tag_map[pos_tags[UH]] = pos_tags_real[UH];
				pos_tag_map[pos_tags[VB]] = pos_tags_real[VB];
				pos_tag_map[pos_tags[VBD]] = pos_tags_real[VBD];
				pos_tag_map[pos_tags[VBG]] = pos_tags_real[VBG];
				pos_tag_map[pos_tags[VBN]] = pos_tags_real[VBN];
				pos_tag_map[pos_tags[VBP]] = pos_tags_real[VBP];
				pos_tag_map[pos_tags[VBZ]] = pos_tags_real[VBZ];
				pos_tag_map[pos_tags[WDT]] = pos_tags_real[WDT];
				pos_tag_map[pos_tags[WP]] = pos_tags_real[WP];
				pos_tag_map[pos_tags[WPDOLLAR]] = pos_tags_real[WPDOLLAR];
				pos_tag_map[pos_tags[WRB]] = pos_tags_real[WRB];
				pos_tag_map[""] = "";


				pos_tag_table[pos_tags[DOLLAR]] = DOLLAR;
				pos_tag_table[pos_tags[PERIOD]] = PERIOD;
				pos_tag_table[pos_tags[COMMA]] = COMMA;
				pos_tag_table[pos_tags[COLON]] = COLON;
				pos_tag_table[pos_tags[LEFT_QUOTATION]] = LEFT_QUOTATION;
				pos_tag_table[pos_tags[RIGHT_QUOTATION]] = RIGHT_QUOTATION;
				pos_tag_table[pos_tags[LEFT_BRACKET]] = LEFT_BRACKET;
				pos_tag_table[pos_tags[RIGHT_BRACKET]] = RIGHT_BRACKET;
				pos_tag_table[pos_tags[AFX]] = AFX;
				pos_tag_table[pos_tags[CC]] = CC;
				pos_tag_table[pos_tags[CD]] = CD;
				pos_tag_table[pos_tags[DT]] = DT;
				pos_tag_table[pos_tags[EX]] = EX;
				pos_tag_table[pos_tags[FW]] = FW;
				pos_tag_table[pos_tags[HYPH]] = HYPH;
				pos_tag_table[pos_tags[IN]] = IN;
				pos_tag_table[pos_tags[JJ]] = JJ;
				pos_tag_table[pos_tags[JJR]] = JJR;
				pos_tag_table[pos_tags[JJS]] = JJS;
				pos_tag_table[pos_tags[LS]] = LS;
				pos_tag_table[pos_tags[MD]] = MD;
				pos_tag_table[pos_tags[NN]] = NN;
				pos_tag_table[pos_tags[NNP]] = NNP;
				pos_tag_table[pos_tags[NNPS]] = NNPS;
				pos_tag_table[pos_tags[NNS]] = NNS;
				pos_tag_table[pos_tags[PDT]] = PDT;
				pos_tag_table[pos_tags[POS]] = POS;
				pos_tag_table[pos_tags[PRP]] = PRP;
				pos_tag_table[pos_tags[PRPDOLLAR]] = PRPDOLLAR;
				pos_tag_table[pos_tags[RB]] = RB;
				pos_tag_table[pos_tags[RBR]] = RBR;
				pos_tag_table[pos_tags[RBS]] = RBS;
				pos_tag_table[pos_tags[RP]] = RP;
				pos_tag_table[pos_tags[SYM]] = SYM;
				pos_tag_table[pos_tags[TO]] = TO;
				pos_tag_table[pos_tags[token]] = token;
				pos_tag_table[pos_tags[UH]] = UH;
				pos_tag_table[pos_tags[VB]] = VB;
				pos_tag_table[pos_tags[VBD]] = VBD;
				pos_tag_table[pos_tags[VBG]] = VBG;
				pos_tag_table[pos_tags[VBN]] = VBN;
				pos_tag_table[pos_tags[VBP]] = VBP;
				pos_tag_table[pos_tags[VBZ]] = VBZ;
				pos_tag_table[pos_tags[WDT]] = WDT;
				pos_tag_table[pos_tags[WP]] = WP;
				pos_tag_table[pos_tags[WPDOLLAR]] = WPDOLLAR;
				pos_tag_table[pos_tags[WRB]] = WRB;
				pos_tag_table[""] = NONE;
			}
		};

		nlp_tag_proxy ntp;
	}
}

#endif /* NLP_TAG_MAP_H_ */
