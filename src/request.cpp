/*
 * request.cpp
 *
 *  Created on: 06/06/2013
 *      Author: monfee
 */

#include "request.h"

namespace QLINK {

request::request() : wikified_(false), last_request_time_(time(0)) {

}

request::request(const request& rsq) {
	this->last_request_time_ = rsq.get_last_request_time();
	this->page_ = rsq.get_page();
	this->wikified_ = rsq.is_wikified();
}

request::~request() {

}

} /* namespace QLINK */
