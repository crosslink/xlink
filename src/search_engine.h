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
 * search_engine.h
 *
 *  Created on: Sep 30, 2009
 *
 */

#ifndef SEARCH_ENGINE_H_
#define SEARCH_ENGINE_H_

typedef	void * SE;

class search_engine
{
protected:
	char **docids_;
	long long hits_;

private:
	SE	instance_;

public:
	search_engine();
	virtual ~search_engine();

	long long hits() { return hits_; }
	char **docids() const { return docids_; }
	virtual void search(const char *term) = 0;
};

#endif /* SEARCH_ENGINE_H_ */
