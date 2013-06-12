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
 * algorithm_ltw_incoming_search_tn.h
 *
 *  Created on: Aug 17, 2009
 *      Author: monfee
 */

#ifndef ALGORITHM_LTW_INCOMING_SEARCH_TN_H_
#define ALGORITHM_LTW_INCOMING_SEARCH_TN_H_

#include "algorithm.h"

#ifdef wITH_ATIRE
#include <atire_api.h>
#endif

namespace QLINK {

	/*
	 * to creat the incoming links by searching topic name
	 */
	class algorithm_ltw_incoming_search_tn: public algorithm
	{
	protected:
		char **docids_;
		long long hits_;

	private:
#ifdef wITH_ATIRE
		ATIRE_API *ant_;
#endif

	public:
		algorithm_ltw_incoming_search_tn(ltw_task *task);
		virtual ~algorithm_ltw_incoming_search_tn();

		virtual void process_topic(ltw_topic *a_topic);

	private:
		void init_search_engine();
	};

}
#endif /* ALGORITHM_LTW_INCOMING_SEARCH_TN_H_ */
