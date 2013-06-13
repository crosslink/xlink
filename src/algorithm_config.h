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
 * algorithm_config.h
 *
 *  Created on: Aug 4, 2009
 *
 */

#ifndef ALGORITHM_CONFIG_H_
#define ALGORITHM_CONFIG_H_

/*
 *
 */
#include "config.h"

namespace QLINK {
	class algorithm_config: public config {
	public:
		static const char *DEFAULT_CONFIG_FILENAME;

	public:
		algorithm_config(const char *name);
		algorithm_config();
		virtual ~algorithm_config();
	};
}

#endif /* ALGORITHM_CONFIG_H_ */
