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
 * run_config.h
 *
 *  Created on: Aug 3, 2009
 *      Author: monfee
 */

#ifndef RUN_CONFIG_H_
#define RUN_CONFIG_H_

#include "config.h"
#include <string>

	namespace QLINK {

	/*
	 * LTW run config
	 */
	class run_config : public config {
	public:
		run_config(char *name);
		virtual ~run_config();

		std::string get_algorithm_outgoing_name();
		std::string get_algorithm_incoming_name();
	};

}
#endif /* RUN_CONFIG_H_ */
