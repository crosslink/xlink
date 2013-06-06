/*
 * session.h
 *
 *  Created on: 06/06/2013
 *      Author: monfee
 */

#ifndef SESSION_H_
#define SESSION_H_

#include <string>
#include <map>

#include "request.h"

namespace QLINK {

class session {
private:
	std::string 										session_id_;
	std::map<std::string, request>			request_;

public:
	session();
	virtual ~session();
};

} /* namespace QLINK */
#endif /* SESSION_H_ */
