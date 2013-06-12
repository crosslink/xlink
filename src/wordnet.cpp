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
	return last_val;
}


