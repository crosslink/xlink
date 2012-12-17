/*
 * wordnet.cpp
 *
 *  Created on: Dec 17, 2012
 *      Author: monfee
 */

#include "wordnet.h"

#include <wn.h>

wordnet::wordnet() {
	wninit();
}

wordnet::~wordnet() {

}

int wordnet::check(char* searchword) {
	strtolower(strsubst(searchword, ' ', '_'));

	last_val = 0;
	unsigned int search;

	for (int i = 1; i <= NUMPARTS; i++) {
		if ((search = is_defined(searchword, 1)) != 0) {
	//		printsearches(searchword, 1, search);
			switch(i) {
			case 1:
				last_val += NOUN;
				break;
			case 2:
				last_val += VERB;
				break;
			case 3:
				last_val += ADJECTIVE;
				break;
			case 4:
				last_val += ADVERB;
				break;
			default:
				break;
			}
		}
	}
}


