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
 * translation.h
 *
 *  Created on: Apr 18, 2011
 *      Author: monfee
 */

#ifndef TRANSLATION_H_
#define TRANSLATION_H_

#include <map>
#include <string>

#include "pattern_singleton.h"

namespace QLINK {
	class translation : public pattern_singleton<translation>
	{
	public:
		static const char *CACHE_FOLDER;

	private:
		bool								cache_it_;
		std::map<std::string, std::string>  translations_;

	public:
		translation();
		virtual ~translation();

		std::string translate(const char *word, const char *language_pair);
	};
}

#endif /* TRANSLATION_H_ */
