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
 * wikipedia.h
 *
 *  Created on: Oct 7, 2009
 *
 */

#ifndef WIKIPEDIA_H_
#define WIKIPEDIA_H_

#include <string>
#include <utility>

namespace QLINK {

	struct wiki_entry{
		long 			id;
		std::string 	title;
		std::string		description;
	};

	class wikipedia
	{
	public:
		wikipedia();
		virtual ~wikipedia();

		static std::pair<std::string, std::string> process_title(std::string& orig, bool lowercase/*, bool english_only*/);
		static std::string get_article_abstract_by_id(std::string lang, std::string id);
	};

}

#endif /* WIKIPEDIA_H_ */
