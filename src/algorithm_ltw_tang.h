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
 * algorithm_ltw_tang.h
 *
 *  Created on: Aug 13, 2009
 *
 */

#ifndef ALGORITHM_LTW_TANG_H_
#define ALGORITHM_LTW_TANG_H_

#include "algorithm_out.h"

namespace QLINK {

	class algorithm_ltw_tang: public algorithm_out
	{
	public:
		algorithm_ltw_tang(ltw_task *task);
		virtual ~algorithm_ltw_tang();

		int init();
	};

}
#endif /* ALGORITHM_LTW_TANG_H_ */
