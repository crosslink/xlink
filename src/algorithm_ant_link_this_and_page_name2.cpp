/*
 * algorithm_ant_link_this_and_page_name2.cpp
 *
 *  Created on: Dec 18, 2012
 *      Author: monfee
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
	return QLINK::algorithm_ant_link_this::find_term_in_list(term);
}

void algorithm_ant_link_this_and_page_name2::add_link(
		ANT_link_term* link_term, char** term_list, long int offset) {
	QLINK::algorithm_ant_link_this::add_link(link_term, term_list, offset);
}

void algorithm_ant_link_this_and_page_name2::process_terms(
		char** term_list, const char* source) {
	QLINK::algorithm_ant_link_this::process_terms(term_list, source);

//	if (links_->size() < 250)
//	simply added the page name to end of link list
		QLINK::algorithm_page_name::process_terms(term_list, source);
}


