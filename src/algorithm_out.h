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
 * algorithm_out.h
 *
 *  Created on: Sep 6, 2010
 *
 */

#ifndef ALGORITHM_OUT_H_
#define ALGORITHM_OUT_H_

#include "algorithm.h"
#include "application_out.h"

namespace QLINK
{

	class algorithm_out: public QLINK::algorithm
	{
	public:
		algorithm_out(ltw_task *task);
//		algorithm_out() {}
		virtual ~algorithm_out();

	public:
		void list_anchors(application_out &anchors_list);

	protected:
		virtual void recommend_anchors(links* lx, char **term_list, const char *source);
		virtual void add_link(links* lx, ANT_link_term *term, char **term_list, long offset) {}
		long assign_link_term(char *buffer, char **term_list);
	};

}

#endif /* ALGORITHM_OUT_H_ */
