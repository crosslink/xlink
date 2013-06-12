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
