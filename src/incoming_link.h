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
 * incoming_link.h
 *
 *  Created on: Aug 3, 2009
 *
 */

#ifndef INCOMING_LINK_H_
#define INCOMING_LINK_H_

#include "link.h"

namespace QLINK {

	/*
	 *
	 */
	class incoming_link: public link {
	public:
		incoming_link();
		virtual ~incoming_link();

		void print_header();
		void print_footer();

		//void print_anchor(long beps_to_print = 1);
		//void print_bep(long beps_to_print = 1);
	};

	inline void incoming_link::print_header() {  }
	inline void incoming_link::print_footer() {  }
//	inline void incoming_link::print_header() { printf("<linkfrom>\n"); }
//	inline void incoming_link::print_footer() { printf("</linkfrom>\n"); }
}

#endif /* INCOMING_LINK_H_ */
