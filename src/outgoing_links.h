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
 * outgoing_links.h
 *
 *  Created on: Aug 16, 2009
 *      Author: monfee
 */

#ifndef OUTGOING_LINKS_H_
#define OUTGOING_LINKS_H_

#include "links.h"
#include <stdio.h>

namespace QLINK {

	class outgoing_links : public links
	{
	private:

	public:
		outgoing_links();
		outgoing_links(ltw_topic *a_topic, bool need_crosslink = false);
		virtual ~outgoing_links();

		virtual void print_header();
		virtual void print_footer();

		void find_anchor();

	protected:
		virtual void init_links();

		virtual void print_link_tag_header();
		virtual void print_link_tag_footer();

		void print_links(long orphan_docid, const char *orphan_name, long links_to_print = 250, long max_targets_per_anchor = 1, long mode = 1);
		void print_anchors(long orphan_docid, const char *orphan_name);

		virtual link *link_maker();

	private:
		virtual void init();
	};

//	void outgoing_links::print_link_tag_header() { printf("		<linkto>"); }
//	void outgoing_links::print_link_tag_footer() { printf("</linkto>\n"); }

}

#endif /* OUTGOING_LINKS_H_ */
