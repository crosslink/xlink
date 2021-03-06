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
 * incoming_links.h
 *
 *  Created on: Aug 16, 2009
 *
 */

#ifndef INCOMING_LINKS_H_
#define INCOMING_LINKS_H_

#include "links.h"
#include <stdio.h>

namespace QLINK {

	class incoming_links : public links
	{
	public:
		incoming_links();
		incoming_links(ltw_topic *a_topic);
		virtual ~incoming_links();

		virtual void print_header();
		virtual void print_footer();

		void find_anchor();

	protected:
		void print_link_tag_header();
		void print_link_tag_footer();

		virtual void init_links();

		void print_links(long orphan_docid, const char *orphan_name, long links_to_print = 1, long max_targets_per_anchor = 250, long mode = 1);
		void print_anchors(long orphan_docid, const char *orphan_name);

		virtual link *link_maker();

	private:
		virtual void init();
	};

	inline void incoming_links::print_link_tag_header() { printf("		<linkfrom>"); }
	inline void incoming_links::print_link_tag_footer() { printf("</linkfrom>\n"); }
}

#endif /* INCOMING_LINKS_H_ */
