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
 * name_container.h
 *
 *  Created on: Sep 30, 2009
 *
 */

#ifndef NAME_CONTAINER_H_
#define NAME_CONTAINER_H_

namespace QLINK {

	class name_container
	{
	public:
		name_container();
		virtual ~name_container();
		static name_container& instance();

	private:
		void init();
	};

	inline name_container& name_container::instance() {
		static name_container inst;
		return inst;
	}

}

#endif /* NAME_CONTAINER_H_ */
