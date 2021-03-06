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
 * cmdline_options.h
 *
 *  Created on: Aug 11, 2009
 *
 */

#ifndef CMDLINE_OPTIONS_H_
#define CMDLINE_OPTIONS_H_

class cmdline_options
{
public:
	static int argc;
	static char **argv;

public:
	cmdline_options();
	virtual ~cmdline_options();
};

#endif /* CMDLINE_OPTIONS_H_ */
