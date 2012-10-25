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
