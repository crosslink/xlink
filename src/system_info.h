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
 * system_info.h
 *
 *  Created on: Aug 3, 2009
 *      Author: monfee
 */

#ifndef SYSTEM_INFO_H_
#define SYSTEM_INFO_H_

#include <string>
/*
 *
 */
class system_info {
public:
	std::string cpu_info;

public:
	system_info();
	virtual ~system_info();
};

#endif /* SYSTEM_INFO_H_ */
