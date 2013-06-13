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
 * ir_task.h
 *
 *  Created on: Aug 18, 2009
 *
 */

#ifndef IR_TASK_H_
#define IR_TASK_H_

namespace QLINK {

	class ir_task
	{
	public:
		enum task_type { IR_TASK_NONE = 0,
						IR_TASK_LTW = 1
						};

	private:
		task_type	type_;

	public:
		ir_task() : type_(IR_TASK_NONE) {}
		ir_task(task_type type) : type_(type) {}
		virtual ~ir_task() { }

		void type(task_type type) { type_ = type; }
		task_type type() { return type_; }
	};

}
#endif /* IR_TASK_H_ */
