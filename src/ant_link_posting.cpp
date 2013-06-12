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
 * ant_link_posting.cpp
 *
 *  Created on: Oct 14, 2009
 *      Author: monfee
 */

#include "ant_link_posting.h"
#include <stdlib.h>

ANT_link_posting::ANT_link_posting()
{
	docid = -1;
	offset = 0;
	link_frequency = 0;
	doc_link_frequency = 0;
	desc = NULL;
}

ANT_link_posting::~ANT_link_posting()
{
	if (desc)
		free(desc);
}

/*
	ANT_LINK_POSTING::COMPARE()
	---------------------------
*/
inline bool ANT_link_posting::compare(const ANT_link_posting *a, const ANT_link_posting *b)
{
ANT_link_posting *one = NULL, *two = NULL;

one = (ANT_link_posting *)a;
two = (ANT_link_posting *)b;

return two->link_frequency > one->link_frequency; // ? 1 : two->link_frequency == one->link_frequency ? 0 : -1;
}
