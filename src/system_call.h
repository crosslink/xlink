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
 * system_call.h
 *
 *  Created on: Sep 22, 2009
 *      Author: monfee
 */

#ifndef SYSTEM_CALL_H_
#define SYSTEM_CALL_H_

#include <stdio.h>

namespace QLINK {
	class system_call
	{
	public:
		static unsigned const int BUF_SIZE = 1024;

	private:
		FILE *dl_;
		char result_buf_[BUF_SIZE];
		char cmd_buf_[BUF_SIZE];

	public:
		system_call();
		virtual ~system_call();

		void cmd(char *cmd_str);
		char *result() { return result_buf_; }
		char *execute(const char *cmd);
		char *execute() { return execute(cmd_buf_); }
		static system_call& instance();

	private:
		void reset();
	};

	inline system_call& system_call::instance() {
		static system_call inst;
		return inst;
	}

	inline void system_call::reset() {
		*result_buf_ = '\0';
	}
}

#endif /* SYSTEM_CALL_H_ */
