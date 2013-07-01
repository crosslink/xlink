/*
 * xml.h
 *
 *  Created on: 01/07/2013
 *      Author: monfee
 */

#ifndef XML_H_
#define XML_H_

#include "string_utils.h"

inline void un_xmlify(std:string& what) {
	find_and_replace(what, string("&lt;"), string("<"));
	find_and_replace(what, string("&gt;"), string(">"));

	find_and_replace(what, string("&amp;"), string("&"),);
	find_and_replace(what, string("&quot;"), string("\""));
	find_and_replace(what, string("&apos;"), string("'"));
}

inline void xmlify(std:string& what) {
	find_and_replace(what, string("&lt;"), string("<"));
	find_and_replace(what, string("&gt;"), string(">"));

	find_and_replace(what, string("&"), string("&amp;"));
	find_and_replace(what, string("\""), string("&quot;"));
	find_and_replace(what, string("'"), string("&apos;"));
}

#endif /* XML_H_ */
