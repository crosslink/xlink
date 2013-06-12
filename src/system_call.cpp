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
 * system_call.cpp
 *
 *  Created on: Sep 22, 2009
 *      Author: monfee
 */

#include "system_call.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

using namespace QLINK;

system_call::system_call()
{

}

system_call::~system_call()
{

}

void system_call::cmd(char *cmd_str)
{
	strcpy(cmd_buf_, cmd_str);
}

char *system_call::execute(const char *cmd)
{
#if defined (CYGWIN) || defined(cygwin) || defined(__WIN32__) || defined(__CYGWIN32__) || defined(_MSC_VER)

#else
	reset();
	dl_ = popen(cmd, "r");
	if(!dl_){
	  perror("popen");
	  exit(-1);
	}
	else {
		fgets(result_buf_, BUF_SIZE, dl_);
	}
	pclose(dl_);

	int idx = strlen(result_buf_) - 1;
	while (idx > 0) {
		if (isspace(result_buf_[idx]))
			result_buf_[idx] = '\0';
		else
			break;
		--idx;
	}
#endif
	return result_buf_;
}
