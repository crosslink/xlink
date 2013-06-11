/*
 * application_out.cpp
 *
 *  Created on: Sep 16, 2010
 *      Author: monfee
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
