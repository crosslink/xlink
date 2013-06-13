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
 * application_out.cpp
 *
 *  Created on: Sep 16, 2010
 *
 */

#include "application_out.h"
#include <iostream>

#include <string.h>

using namespace std;

namespace QLINK
{

//application_out aout;

application_out::application_out()
{
	out_ = &cout;
	init();
}

application_out::application_out(std::ostream	 *out)
{
	out_ = out;
	init();
}

application_out::~application_out()
{
	if (out_ != NULL) {
		if (out_ != &cout && out_ != &cerr)
			delete out_;
	}
}

void application_out::init() {
	buf_ << "";
}

//void application_out::operator << (const char *content)
//template< typename T >
//application_out &application_out::operator << (T const &content)
//{
//	T *t = 0;
//	buf_ << content;
//	return *this;
//}

void application_out::use_stdout(bool b)
{
	use_stdout_ = b;
	if (use_stdout_) {
		out_ = &cout;
	}
}

void application_out::reset()
{
	buf_.str("");
}

void application_out::printbuf(const char *content)
{
//	buf_ << content;
	buf_.write(content, strlen(content));
}

void application_out::flush()
{
	*out_ << buf_.str();
}

}
