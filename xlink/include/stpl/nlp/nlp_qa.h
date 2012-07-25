/******************************************************************************
 * This file is part of the Simple Text Processing Library(STPL).
 * (c) Copyright 2007-2010 TYONLINE TECHNOLOGY PTY. LTD.
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU LESSER GENERAL PUBLIC LICENSE, Version 3 as published by the Free Software
 * Foundation and appearing in the file LICENSE.LGPL included in the
 * packaging of this file.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 *******************************************************************************
 *
 * @author				Ling-Xiang(Eric) Tang
 *
 *******************************************************************************/

#ifndef NLP_QA_H_
#define NLP_QA_H_

namespace stpl
{
	namespace nlp
	{
		enum {DEFINITION = 0, BIOGRAPHY, RELATIONSHIP, EVENT, WHY, PERSON, ORGANIZATION, LOCATION, DATE };

		const char *ntcir_question_types[] = {
				"DEFINITION", "BIOGRAPHY", "RELATIONSHIP", "EVENT", "WHY", "PERSON", "ORGANIZATION", "LOCATION", "DATE"
		};
	}
}
#endif /* NLP_QA_H_ */