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
 * template_comparor.h
 *
 *  Created on: Oct 13, 2009
 *
 */

#ifndef TEMPLATE_COMPAROR_H_
#define TEMPLATE_COMPAROR_H_

#include <functional>

template <typename T>
struct pointer_less_than : public std::binary_function<bool, const T*, const T*> {
	const bool operator()(const T *a, const T * b) const {
		// check for 0
		if (a == 0)
			return b != 0; // if b is also 0, then they are equal, hence a is not < than b
		else if (b == 0)
			return false;
		else {
			const T& one = *a;
			const T& two = *b;
			return one < two;
		}
	}
};

template <typename T>
struct pointer_greater_than : public std::binary_function<bool, const T*, const T*> {
	const bool operator()(const T *a, const T * b) const {
		// check for 0
		if (a == 0)
			return b == 0; // if b is also 0, then they are equal, hence a is not > than b
		else if (b == 0)
			return true;
		else {
			const T& one = *a;
			const T& two = *b;
			return one > two;
		}
	}
};

#endif /* TEMPLATE_COMPAROR_H_ */
