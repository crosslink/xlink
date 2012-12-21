/*
 * algorithm_out.cpp
 *
 *  Created on: Sep 6, 2010
 *      Author: monfee
 */

#include "algorithm_out.h"
#include "ant_link_term.h"
#include "ant_link_parts.h"
#include "ltw_topic.h"

#include "ltw_task.h"

#include <iostream>

using namespace std;

namespace QLINK
{

algorithm_out::algorithm_out(ltw_task *task) : algorithm(task)
{

}

algorithm_out::~algorithm_out()
{

}

void algorithm_out::list_anchors(application_out &anchors_list)
{

	std::vector<link *> link_vector = links_->all_links();
	for (int i = 0; i < link_vector.size(); ++i) {
		anchors_list << link_vector[i]->link_term->term;
		anchors_list << "\n";
	}
}

void algorithm_out::recommend_anchors(links* lx, char **term_list, const char *source)
{
	char **first, **last;
	char *where_to;
	long is_substring, cmp, offset;
	char buffer[1024 * 1024];
//		page_map_t::iterator index_entry = names_map_.end();
//		page_map_t::iterator last_index_entry = index_entry;
	ANT_link_term *index_term = NULL;

	for (first = term_list; *first != NULL; first++)
		{
//			fprintf(stderr, "%s\n", *first);
		current_term_ = *first;
		current_index_ = first - term_list;
		where_to = buffer;
		for (last = first; *last != NULL; last++)
			{
			if (where_to == buffer)
				{
				strcpy(buffer, *first);
				where_to = buffer + strlen(buffer);
				}
			else
				{
				if (segmented_) // segmented text, so we only match the words
					break;

				if (!use_utf8_token_matching_)
					*where_to++ = ' ';
				strcpy(where_to, *last);
				where_to += strlen(*last);
				}

			*where_to = '\0';

//				for the possible debugging later
//				static char di[] = {(char)0xe6, (char)0xa2, (char)0x85};
//				static char xianjin[] = {(char)0xe3, (char)0x80, (char)0x8a, (char)0xe7, (char)0x8e, (char)0xb0};
//				if (memcmp(buffer, xianjin, 6) == 0)
//					fprintf(stderr, "I got you");
//				if (strncmp(*last, "\"", 1)) == 0)
//					fprintf(stderr, "I got you");

//			if (translate_anchor_for_linking_) {
//
//			}
//			else
				index_term = find_term_in_list(buffer);

			if (index_term == NULL)
				break;		// we're after the last term in the list so can stop because we can't be a substring

			if (use_utf8_token_matching_)
				{
				is_substring = FALSE;
				cmp = utf8_token_compare(buffer, index_term->term, &is_substring);
				}
			else
				cmp = string_compare(buffer, index_term->term, lowercase_only);

			if (cmp == 0)		// we're a term in the list
				{
//				if (strcmp("過年", buffer) == 0)
//					cerr << " I caught you" << endl;
				string test("Certified check");
				if (strcasecmp(test.c_str(), current_term_) == 0
						|| strcasecmp(test.c_str(), buffer) == 0
						|| strcasecmp(test.c_str(), index_term->term) == 0)
					cerr << "I got you" << endl;

//				if (!lx->find(buffer)) {
					offset = assign_link_term(buffer, term_list);
					add_link(lx, index_term, term_list, offset);
//				}
				}
			else
				{
				if (use_utf8_token_matching_)
					cmp = is_substring == TRUE ? 0 : 1;
				else
					cmp = memcmp(buffer, index_term->term, strlen(buffer));
				if  (cmp != 0)
					break;		// we're a not a substring so we can't find a longer term
				}
			}
		}
	// debug
	if (lx->all_links_length() > 0)
		fprintf(stderr, "added %d links\n", lx->all_links_length());
}

long algorithm_out::assign_link_term(char *buffer, char **term_list)
{
	long term_len, offset, index;

//	if (!use_utf8_token_matching_) {
//		offset = current_term_ - source_;
//	}
//	else {
		index = current_index_;
		offset = token_address_[index] - source_;
//		strcpy(buffer_, index_term->term);
//	}

	term_len = strlen(buffer);
	char *where_to = buffer_;
	char *start = offset + current_topic_->get_content();
	int count = term_len;
	while (count > 0) {
		if (*start == '<') {
			while (*start != '>') {
//				++start;
				*where_to++ = *start++;
			}
//			++start;
//			*where_to++ = *start++;
		}
		else
			--count;
		*where_to++ = *start++;
	}
//	strncpy(buffer_, offset + current_topic_->get_content(), term_len);

	buffer_[term_len] = '\0';

	if (ltw_task_->is_cjk_lang() && memcmp(buffer_, buffer, term_len) != 0) {
		fprintf(stderr, "WARNING - buffer does not match: [%s], [%s]\n", buffer_, buffer);
		term_len = current_topic_->get_term_len(offset, buffer, ltw_task_->is_cjk_lang());
		strncpy(buffer_, offset + current_topic_->get_content(), term_len);
		buffer_[term_len] = '\0';
	}

#ifdef DEBUG
		if (strlen(buffer_) == 0)
			fprintf(stderr, "WARNING - empty anchor found: [%s], [%s]\n", current_term_, buffer);
//		fprintf(stderr, "WARNING - empty anchor found: [%s], [%s], [%s]\n", current_term_, buffer);
#endif

//	if (offset == 3443)
//		cerr << " I caught you" << endl;
	return offset;
}

}
