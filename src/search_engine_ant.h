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
 * search_engine_ant.h
 *
 *  Created on: Sep 30, 2009
 *      Author: monfee
 */


#ifndef SEARCH_ENGINE_ANT_H_
#define SEARCH_ENGINE_ANT_H_

#ifdef WITH_ATIRE
#include "pattern_singleton.h"

#include <string>

#include "config.h"

typedef void ANT;

class search_engine_ant: public pattern_singleton<search_engine_ant>
{
public:
	static const char *ANT_CONFIG_FILE;
	static const char *ANT_INDEX_FILE_PROPERTY;
	static const char *ANT_DOCLIST_FILE_PROPERTY;

private:
	ANT				*ant_;
	QLINK::config	*config_ant_;
	std::string		index_filename_;
	std::string		doclist_filename_;
	bool			segmentation_;

protected:
	const char **docids_;
	long long hits_;

public:
	search_engine_ant();
	search_engine_ant(const char *doclist_filename, const char *index_filename, bool segmentation = true);
	virtual ~search_engine_ant();

	long long hits() { return hits_; }
	const char **docids() const { return docids_; }

	const char ** search(const char * term);

private:
	void init();
};

#endif

#endif /* SEARCH_ENGINE_ANT_H_ */

