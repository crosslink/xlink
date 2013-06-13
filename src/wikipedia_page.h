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
 * wikipedia_page.h
 *
 *  Created on: Mar 22, 2011
 *
 */

#ifndef WIKIPEDIA_PAGE_H_
#define WIKIPEDIA_PAGE_H_

namespace QLINK
{

class wikipedia_page
{
private:
	static char *century_list[];
	static long century_list_len;

public:
	wikipedia_page();
	virtual ~wikipedia_page();

	bool is_century(const char *term);
	bool is_year(const char *term);
	bool is_number(const char *term);
};

}

#endif /* WIKIPEDIA_PAGE_H_ */
