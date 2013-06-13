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
	std::string		url_;

public:
	request();
	request(const char *url, const char *page);
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

	const std::string& get_url() const {
		return url_;
	}

	void set_url(const std::string& url) {
		url_ = url;
	}
};

} /* namespace QLINK */
#endif /* REQUEST_H_ */
