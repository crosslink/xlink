/*
 * wordnet.h
 *
 *  Created on: Dec 17, 2012
 *      Author: monfee
 */

#ifndef WORDNET_H_
#define WORDNET_H_

#include "singleton.h"

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
	bool is_noun() { return last_val & NOUN; }
	bool is_verb() { return last_val & VERB; }
	bool is_adjective() { return last_val & ADJECTIVE; }
	bool is_adverb() { return last_val & ADVERB; }
};

#endif /* WORDNET_H_ */
