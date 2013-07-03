/*
 * xml.h
 *
 *  Created on: 01/07/2013
 *      Author: monfee
 */

#ifndef XML_H_
#define XML_H_

#include <string>


#include "string_utils.h"

inline void un_xmlify(std::string& what) {
	find_and_replace(what, std::string("&lt;"), std::string("<"));
	find_and_replace(what, std::string("&gt;"), std::string(">"));

	find_and_replace(what, std::string("&quot;"), std::string("\""));
	find_and_replace(what, std::string("&apos;"), std::string("'"));
	find_and_replace(what, std::string("&amp;"), std::string("&"));
}

inline void xmlify(std::string& what) {
	find_and_replace(what, std::string("&"), std::string("&amp;"));
	find_and_replace(what, std::string("\""), std::string("&quot;"));
	find_and_replace(what, std::string("'"), std::string("&apos;"));

	find_and_replace(what, std::string("<"), std::string("&lt;"));
	find_and_replace(what, std::string(">"), std::string("&gt;"));
}

#endif /* XML_H_ */
