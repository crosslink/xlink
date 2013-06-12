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
 * algorithm_ant_crosslink_this.h
 *
 *  Created on: Apr 30, 2011
 *      Author: monfee
 */

#ifndef ALOGRITHM_ANT_CROSSLINK_THIS_H_
#define ALOGRITHM_ANT_CROSSLINK_THIS_H_

#include "algorithm_ant_link_this_and_page_name2.h"

namespace QLINK
{

class algorithm_ant_crosslink_this: public QLINK::algorithm_ant_link_this_and_page_name2
{
private:
	algorithm_ant_link_this		find_anchors_with_this_;

protected:
	virtual ANT_link_term *find_term_in_list(const char *value);
	virtual void add_link(links* lx, ANT_link_term *term, char **term_list, long offset);

public:
	algorithm_ant_crosslink_this(ltw_task *task);
	virtual ~algorithm_ant_crosslink_this();

	virtual int init_params(int argc, char *argv[]);
};

}

#endif /* ALOGRITHM_ANT_CROSSLINK_THIS_H_ */
