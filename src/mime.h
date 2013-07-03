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
 * mime.h
 *
 *  Created on: 03/07/2013
 */

#ifndef MIME_H_
#define MIME_H_

#include <map>
#include <string>

namespace QLINK {

class mime {
public:
	static std::map<std::string, const char *> 		MIME_TYPE;
	static int 														TYPE_COUNT;

public:
	mime();
	virtual ~mime();

	static const char *get_mime_type(const char *filename);
};

} /* namespace QLINK */
#endif /* MIME_H_ */
