/*
 * target.h
 *
 *  Created on: 01/07/2013
 *      Author: monfee
 */

#ifndef TARGET_H_
#define TARGET_H_

#include <string>

namespace QLINK {

class target {
private:
	std::string lang_;
	std::string target_;
	std::string title_;

public:
	target();
	target(std::string lang, std::string a_target, std::string title);
	target(const target& a_target);
	virtual ~target();

	const std::string& get_lang() const {
		return lang_;
	}

	void set_lang(const std::string& lang) {
		lang_ = lang;
	}

	const std::string& get_target() const {
		return target_;
	}

	void set_target(const std::string& target) {
		target_ = target;
	}

	const std::string& get_title() const {
		return title_;
	}

	void set_title(const std::string& title) {
		title_ = title;
	}
};

} /* namespace QLINK */
#endif /* TARGET_H_ */
