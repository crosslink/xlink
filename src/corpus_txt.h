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
 * corpus_txt.h
 *
 *  Created on: Sep 21, 2009
 *
 */

#ifndef CORPUS_TXT_H_
#define CORPUS_TXT_H_

#include "corpus.h"

namespace QLINK {

	class corpus_txt: public QLINK::corpus
	{
	public:
		corpus_txt();
		virtual ~corpus_txt();
		static corpus_txt& instance();

		void home(std::string path) { home_ = path; }

		//virtual std::string id2docpath(unsigned long id);
		virtual std::string ext() { return ".txt"; }
		virtual std::string wildcard() { return "*.[tT][xT][tT]"; }
	};

	inline corpus_txt& corpus_txt::instance() {
		static corpus_txt inst;
		return inst;
	}

}

#endif /* CORPUS_TXT_H_ */
