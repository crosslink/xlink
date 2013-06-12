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
 * ltw_topic.h
 *
 *  Created on: Sep 9, 2009
 *      Author: monfee
 */

#ifndef LTW_TOPIC_H_
#define LTW_TOPIC_H_

#include "topic.h"
#include "ltw_task.h"

namespace QLINK {
	//class ltw_task;

	class ltw_topic: public QLINK::topic
	{
	private:
		ltw_task	*ltw_task_;
		char		*text_of_xml_;

	public:
		ltw_topic(const char *topic_text);
		virtual ~ltw_topic();

		void set_ltw_task(ltw_task *a_task) { ltw_task_ = a_task; task(static_cast<ir_task *>(ltw_task_)); }
		ltw_task *get_ltw_task() { return ltw_task_; }

		const char *get_text();
		void xml_to_text();

		long get_term_len(long offset, char *term, bool is_cjk_lang);
	};

}

#endif /* LTW_TOPIC_H_ */
