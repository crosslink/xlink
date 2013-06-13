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
 * algorithm_ltw_incoming_a2b_search_tn.h
 *
 *  Created on: Sep 14, 2009
 *
 */

#ifndef ALGORITHM_LTW_INCOMING_A2B_SEARCH_TN_H_
#define ALGORITHM_LTW_INCOMING_A2B_SEARCH_TN_H_

#include "algorithm_ltw_incoming_search_tn.h"

namespace QLINK {
	class link;
	class ltw_topic;
	class algorithm_bep;

	class algorithm_ltw_incoming_a2b_search_tn: public QLINK::algorithm_ltw_incoming_search_tn
	{
//	private:
//		algorithm_bep	*bep_algor_;

	public:
		algorithm_ltw_incoming_a2b_search_tn(ltw_task *task);
		virtual ~algorithm_ltw_incoming_a2b_search_tn();

//		void process_topic(ltw_topic *a_topic);
//
//	private:
//		void find_anchor_and_bep(ltw_topic *a_topic, link* curr_link);
//		void process_links(ltw_topic *a_topic);
	};

}

#endif /* ALGORITHM_LTW_INCOMING_A2B_SEARCH_TN_H_ */
