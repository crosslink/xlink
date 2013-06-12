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
//	static T *inst_ptr_;

public:
	pattern_singleton() {
//		inst_ptr_ = 0;
	}

	inline static T& instance() {
//		if (inst_ptr_ == 0) {
			static T inst;
			return inst;
//			inst_ptr_ = & inst;
//		}
//		return *inst_ptr_;
	}

//	T& get_instance_ptr() {
//		return *inst_ptr_;
//	}
//
//	static void set_instance_ptr(T &instance) {
//		*inst_ptr_ = instance;
//	}
//
//	static void set_instance_ptr() {
//		inst_ptr_ = &instance();
//	}
};

#endif /* PATTERN_SINGLETON_H_ */
