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
 * wordnet.h
 *
 *  Created on: Dec 17, 2012
 *
 */

#ifndef WORDNET_H_
#define WORDNET_H_

#include "pattern_singleton.h"

class wordnet : public pattern_singleton<wordnet>  {
public:
	static const int NOUN = 1;
	static const int VERB = 2;
	static const int ADJECTIVE = 4;
	static const int ADVERB = 8;

private:
	int last_val;

public:
	wordnet();
	virtual ~wordnet();

	int check(char *searchword);
	bool is_noun() { return this->is_noun(last_val); }
	bool is_verb() { return this->is_verb(last_val); }
	bool is_adjective() { return this->is_adjective(last_val); }
	bool is_adverb() { return this->is_adverb(last_val); }

	bool is_noun(int val) { return val & NOUN; }
	bool is_verb(int val) { return val & VERB; }
	bool is_adjective(int val) { return val & ADJECTIVE; }
	bool is_adverb(int val) { return val & ADVERB; }
};

#endif /* WORDNET_H_ */
