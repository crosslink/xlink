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
 * application_out.h
 *
 *  Created on: Sep 16, 2010
 *
 */

#ifndef APPLICATION_OUT_H_
#define APPLICATION_OUT_H_

#include <sstream>
#include <ostream>
#include "pattern_singleton.h"

namespace QLINK
{

	class application_out /*: public pattern_singleton<application_out>*/
	{
	public:

	private:
		std::stringstream	 	buf_;
		std::ostream				*out_;
		bool							use_stdout_;

	public:
		application_out();
		application_out(std::ostream	*out);
		virtual ~application_out();

		void use_stdout(bool b);
		void printbuf(const char *content);
		void reset();
		void flush();

		std::string to_string() { return buf_.str(); }

//		template <typename T>
//		application_out& operator << (T const &content);
		template <typename T>
		application_out& operator << (T const &content) {
			buf_ << content;
			return *this;
		}

	private:
		void init();
	};
}

#endif /* APPLICATION_OUT_H_ */
