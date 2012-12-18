/*
 * pattern_singleton.h
 *
 *  Created on: Oct 8, 2009
 *      Author: monfee
 */

#ifndef PATTERN_SINGLETON_H_
#define PATTERN_SINGLETON_H_

template <typename T>
class pattern_singleton
{
protected:
//	static T inst;
	static T *inst_ptr_;

public:
	pattern_singleton() {
//		set_instance();
	}

	inline static T& instance() {
		static T inst;
		return inst;
	}

	T& get_instance_ptr() {
		return *inst_ptr_;
	}

	void set_instance_ptr(T& instance) {
		inst_ptr_ = &instance;
	}

	void set_instance_ptr() {
		inst_ptr_ = &instance();
	}
};

#endif /* PATTERN_SINGLETON_H_ */
