/*
 * request.h
 *
 *  Created on: 06/06/2013
 *      Author: monfee
 */

#ifndef REQUEST_H_
#define REQUEST_H_

#include <string>
#include <ctime>

namespace QLINK {

class request {
private:
	std::string		page_;
	time_t			last_request_time_;
	bool				wikified_;

public:
	request();
	request(const request& rsq);
	virtual ~request();

	const std::string& get_page() const {
		return page_;
	}

	void set_page(const std::string& page) {
		page_ = page;
	}

	time_t get_last_request_time() const {
		return last_request_time_;
	}

	void set_last_request_time(time_t last_request_time) {
		last_request_time_ = last_request_time;
	}

	bool is_wikified() const {
		return wikified_;
	}

	void set_wikified(bool wikified) {
		wikified_ = wikified;
	}

	void apply_links(const std::string& links_xml);
};

} /* namespace QLINK */
#endif /* REQUEST_H_ */
