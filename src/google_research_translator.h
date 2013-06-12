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
 * googler_esearch_translator.h
 *
 *  Created on: Apr 17, 2012
 *      Author: monfee
 */

#ifndef GOOGLER_ESEARCH_TRANSLATOR_H_
#define GOOGLER_ESEARCH_TRANSLATOR_H_

#include "google_translator.h"

class google_research_translator: public google_translator {
public:
	static const char *GOOGLE_TRANSLATE_RESEARCH_URL_TEMPLATE;
	static const char *GOOGLE_TRANSLATE_RESEARCH_API_KEY_FILE;

	static const char *GOOGLE_TRANSLATE_RESEARCH_AUTH_HEADER;

public:
	google_research_translator();
	virtual ~google_research_translator();

	virtual std::string get_translation(const char *content);

	static google_research_translator& get_instance();
	virtual void initialize(int do_what = DO_NOTHING);

protected:
//private:
	void init(int do_what = DO_NOTHING);
//	static void set_key();
	virtual void set_key();

};

#endif /* GOOGLER_ESEARCH_TRANSLATOR_H_ */
