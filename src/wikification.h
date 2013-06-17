/*
 * wikification.h
 *
 *  Created on: 14/06/2013
 *      Author: monfee
 */

#ifndef WIKIFICATION_H_
#define WIKIFICATION_H_

#include <string>

namespace QLINK {

class wikification {
public:
	wikification();
	virtual ~wikification();

	static std::string linkify(const std::string& links_xml, const std::string& page);
	static void linkify(const std::string& links_xml, const std::string& page, std::string& wikified_page);
	static void linkify(const char *links_xml, const char *page, std::string& wikified_page);
};

} /* namespace QLINK */
#endif /* WIKIFICATION_H_ */
