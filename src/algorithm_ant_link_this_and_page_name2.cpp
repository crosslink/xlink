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
 * algorithm_ant_link_this_and_page_name2.cpp
 *
 *  Created on: Dec 18, 2012
 *
 */

#include "algorithm_ant_link_this_and_page_name2.h"

using namespace QLINK;

algorithm_ant_link_this_and_page_name2::algorithm_ant_link_this_and_page_name2(
		ltw_task* task) : algorithm_ant_link_this(task), algorithm_page_name(task), algorithm_out(task){

}

algorithm_ant_link_this_and_page_name2::~algorithm_ant_link_this_and_page_name2() {

}

ANT_link_term* algorithm_ant_link_this_and_page_name2::find_term_in_list(
		const char* term) {
	if (mode == LINK_THIS)
		return QLINK::algorithm_ant_link_this::find_term_in_list(term);
	else if (mode == PAGE_NAME)
		return QLINK::algorithm_page_name::find_term_in_list(term);
	return NULL;
}

void algorithm_ant_link_this_and_page_name2::add_link(links* lx,
		ANT_link_term* link_term, char** term_list, long int offset) {
	if (mode == LINK_THIS)
		QLINK::algorithm_ant_link_this::add_link(links_, link_term, term_list, offset);
	else if (mode == PAGE_NAME)
		QLINK::algorithm_page_name::add_link(&g_links_, link_term, term_list, offset);
}

void algorithm_ant_link_this_and_page_name2::process_terms(
		char** term_list, const char* source) {
	mode = LINK_THIS;

	QLINK::algorithm_ant_link_this::process_terms(term_list, source);

//	if (links_->size() < 250)
//	simply added the page name to end of link list
	mode = PAGE_NAME;
	g_links_.set_topic(current_topic_);
	QLINK::algorithm_page_name::process_terms(&g_links_, term_list, source);
	fprintf(stderr, "Total %d links found from page name matching\n", g_links_.all_links_length());

	std::vector<link *>& g_link_array = g_links_.all_links();
	link *g_link = NULL;
	int i = 0;
	for (i = 0; i < g_link_array.size(); i++) {
		g_link = g_link_array[i];

		if (links_->find(g_link->term) == NULL)
			link *new_link = links_->push_link(g_link);
			//new_link->require_cleanup();
	}
}


