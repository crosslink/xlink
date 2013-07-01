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
 * anchor.h
 *
 *  Created on: 13/06/2013
 *
 */

#ifndef ANCHOR_H_
#define ANCHOR_H_

#include <string>
#include <vector>

#include "target.h"

namespace QLINK {
typedef 	target 	target_type;

class anchor {
private:
	long				offset_;
	std::string		name_;

	std::vector<target_type> targets_;

public:
	anchor();
	anchor(std::string &name, long offset);
	virtual ~anchor();

	const std::string& get_name() const {
		return name_;
	}

	void set_name(const std::string& name) {
		name_ = name;
	}

	long get_offset() const {
		return offset_;
	}

	void set_offset(long offset) {
		offset_ = offset;
	}

	bool operator<(const anchor &rhs_anchor) const { return this->get_offset() < rhs_anchor.get_offset(); }

	std::vector<target_type>& get_targets() {
		return targets_;
	}

	const target_type& get_target(int index = 0) const { return targets_[index]; }

	void add_target(const target_type& target) {
		targets_.push_back(target);
	}
};

} /* namespace QLINK */
#endif /* ANCHOR_H_ */
