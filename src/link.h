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
 * link.h
 *
 *  Created on: Aug 3, 2009
 *
 */

#ifndef LINK_H_
#define LINK_H_

#include <string>

#include "ant_link.h"
#include "application_out.h"

namespace QLINK {
	class algorithm;
	class topic;

	/*
	 *
	 */
	class link : public ANT_link {
	public:
		static long				fill_anchor_with_ir_results;
		static long 				translate_anchor_for_linking;
		static bool				crosslink_me;

	public:
		char							source_lang[5];
		char 						target_lang[5];

	private:
		bool							to_clean_;
		application_out			*aout_;

	public:
		link();
		virtual ~link();

		virtual bool print_target(long anchor = 0, algorithm *algor = NULL);
		virtual bool print_anchor(topic *topic_ptr, long beps_to_print = 5, bool id_or_name = true, algorithm *algor = NULL);
		virtual void print_bep(long beps_to_print = 1);
		virtual void print();
		virtual void print_header() {}
		virtual void print_footer() {};

		void require_cleanup() { to_clean_ = true; }

	public:
		static bool compare(const link *a, const link *b);
		static bool final_compare(const link *a, const link *b);
		static bool string_target_compare(const link *a, const link *b);
		static bool term_compare(const link *a, const link *b);

		const char * get_target_lang() const { return target_lang; };
		const char * get_source_lang() const { return source_lang; };

		bool operator==(const link& rhs);
		bool operator==(const char *term);

		void set_application_out(application_out *out) {aout_ = out; }
	};

	class link_string_target_compare {
	public:
		const bool operator()(const link *a, const link * b) const;
	};

	class link_compare {
	public:
		const bool operator()(const link *a, const link * b) const;
	};

	class term_compare {
	public:
		const bool operator()(const link *a, const link * b) const;
	};
}
#endif /* LINK_H_ */
