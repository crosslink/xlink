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
 * run_config.cpp
 *
 *  Created on: Aug 3, 2009
 *
 */

#include "run_config.h"

using namespace QLINK;


run_config::run_config(char *name) : config(name) {

}

run_config::~run_config() {
}

std::string run_config::get_algorithm_outgoing_name()
{
	return get_value("algorithm_outgoing");
}

std::string run_config::get_algorithm_incoming_name()
{
	return get_value("algorithm_incoming");
}
