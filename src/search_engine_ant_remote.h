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
 * search_engine_ant_remote.h
 *
 *  Created on: Oct 25, 2012
 *      Author: monfee
 */

#ifndef SEARCH_ENGINE_ANT_REMOTE_H_
#define SEARCH_ENGINE_ANT_REMOTE_H_

#include <atire_api_remote.h>
#include <vector>
#include <string>

#include "pattern_singleton.h"

class search_engine_ant_remote : public pattern_singleton<search_engine_ant_remote> {
private:
	ATIRE_API_remote socket;

public:
	search_engine_ant_remote();
	virtual ~search_engine_ant_remote();

	long search(const char *query, std::vector<std::string> *result, int how_many_neede = 5);
};

#endif /* SEARCH_ENGINE_ANT_REMOTE_H_ */
