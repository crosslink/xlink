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
};

} /* namespace QLINK */
#endif /* WIKIFICATION_H_ */
