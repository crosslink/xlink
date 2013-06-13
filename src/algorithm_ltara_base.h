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
 * algorithm_ltara_base.h
 *
 *  Created on: Oct 17, 2009
 *
 */

#ifndef ALGORITHM_LTARA_BASE_H_
#define ALGORITHM_LTARA_BASE_H_

#include "algorithm_ant_link_this_and_page_name.h"

namespace QLINK {

	class algorithm_ltara_base: public QLINK::algorithm_ant_link_this_and_page_name
	{
	public:
		typedef std::map<long,  char *>			id_name_map_t;

	private:
		id_name_map_t							id_name_map_;

	public:
//		algorithm_ltara_base(links *links_list);
		algorithm_ltara_base(ltw_task *task);
		virtual ~algorithm_ltara_base();

	private:
		void load_names();
		void init();
	};

}

#endif /* ALGORITHM_LTARA_BASE_H_ */
