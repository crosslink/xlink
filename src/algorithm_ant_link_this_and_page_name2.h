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
 * algorithm_ant_link_this_and_page_name2.h
 *
 *  Created on: Dec 18, 2012
 *      Author: monfee
 */

#ifndef ALGORITHM_ANT_LINK_THIS_AND_PAGE_NAME2_H_
#define ALGORITHM_ANT_LINK_THIS_AND_PAGE_NAME2_H_

#include "algorithm_ant_link_this.h"
#include "algorithm_page_name.h"

namespace QLINK {
	class algorithm_ant_link_this_and_page_name2 : public QLINK::algorithm_ant_link_this, public QLINK::algorithm_page_name
	{
	public:
		enum {PAGE_NAME, LINK_THIS};

	private:
		int mode;
		links g_links_;

	public:
		algorithm_ant_link_this_and_page_name2(ltw_task *task);
		virtual ~algorithm_ant_link_this_and_page_name2();

		virtual ANT_link_term* find_term_in_list(const char *term);
		virtual void add_link(links* lx, ANT_link_term *link_term, char **term_list, long int offset);

	protected:
		virtual void process_terms(char **term_list, const char *source);

	};
}

#endif /* ALGORITHM_ANT_LINK_THIS_AND_PAGE_NAME2_H_ */
