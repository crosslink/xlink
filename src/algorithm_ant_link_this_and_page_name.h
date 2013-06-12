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
 * algorithm_ant_link_this_and_page_name.h
 *
 *  Created on: Oct 6, 2009
 *      Author: monfee
 */

#ifndef ALGORITHM_ANT_LINK_THIS_AND_PAGE_NAME_H_
#define ALGORITHM_ANT_LINK_THIS_AND_PAGE_NAME_H_

#include "algorithm_ant_link_this.h"
#include "algorithm_page_name.h"

namespace QLINK {
	//class ANT_link_term;

	class algorithm_ant_link_this_and_page_name: public QLINK::algorithm_ant_link_this, public QLINK::algorithm_page_name
	{
	private:
		links			*k_links_;
		links			*g_links_;

	public:
//		algorithm_ant_link_this_and_page_name(links *links_list);
		algorithm_ant_link_this_and_page_name(ltw_task *task);
		virtual ~algorithm_ant_link_this_and_page_name();

	protected:
		void recommend_anchors(links* lx, char **term_list, const char *source);
		virtual void add_link(links* lx, ANT_link_term *term, char **term_list, long offset) {}
		void process_terms(char **term_list, const char *source);
		void merge_links();
		virtual ANT_link_term *find_term_in_list(const char *value) {}

	private:
		void init();
		void calculate_g_links_score(double max, double min);
	};

}

#endif /* ALGORITHM_ANT_LINK_THIS_AND_PAGE_NAME_H_ */
