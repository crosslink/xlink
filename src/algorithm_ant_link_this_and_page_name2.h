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
		algorithm_ant_link_this_and_page_name2(ltw_task *task);
		virtual ~algorithm_ant_link_this_and_page_name2();

		virtual ANT_link_term* find_term_in_list(const char *term);
		virtual void add_link(ANT_link_term *link_term, char **term_list, long int offset);

	protected:
		virtual void process_terms(char **term_list, const char *source);

	};
}

#endif /* ALGORITHM_ANT_LINK_THIS_AND_PAGE_NAME2_H_ */
