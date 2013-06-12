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
 * algorithm_config.cpp
 *
 *  Created on: Aug 4, 2009
 *      Author: monfee
 */

#include "algorithm_config.h"

using namespace QLINK;

const char *algorithm_config::DEFAULT_CONFIG_FILENAME = "algorithm.conf";

algorithm_config::algorithm_config() : config(DEFAULT_CONFIG_FILENAME) {

}

algorithm_config::algorithm_config(const char *name) : config(name) {

}

algorithm_config::~algorithm_config() {

}
