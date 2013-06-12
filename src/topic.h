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
 * topic.h
 *
 *  Created on: Aug 16, 2009
 *      Author: monfee
 */

#ifndef TOPIC_H_
#define TOPIC_H_

#include "ir_task.h"

namespace QLINK {
	class application_out;

	class topic
	{
	protected:
		char					filename_[1024];
		const char 		*content_;
		long					id_;
		//char				id_name_[1024];
		char					name_[1024];

		ir_task				*task_;

	public:
		topic(const char *filename);
		virtual ~topic();

		void set_filename(const char *filename);
		void set_content(const char *file);
		const char *get_content() const { return content_; }
		long get_id() { return id_; }
		const char *get_name() const { return name_; }

		void task(ir_task *task) { task_ = task; }
		ir_task *task() { return task_; }

		virtual void print_header(application_out& aout);
		virtual void print_footer(application_out& aout);
	};

}

#endif /* TOPIC_H_ */
