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
 * ant_link_posting.h
 *
 *  Created on: Sep 22, 2009
 *
 */

#ifndef ANT_LINK_POSTING_H_
#define ANT_LINK_POSTING_H_

#ifndef NULL
	#define NULL 0
#endif

class ANT_link_posting
{
public:
	long docid;						// target document
	char *desc;						// the description of posting
	long offset;					// the possition of bep for outgoing link; the anchor offset for incoming link, it is not valid until it is assigned one
	long link_frequency;			// number of times the document occurs as the target of a link
	long doc_link_frequency;		// number of documents in which the phrase links to docid

public:
	ANT_link_posting();
	virtual ~ANT_link_posting();
	static bool compare(const ANT_link_posting *a, const ANT_link_posting *b);

//	bool operator>(const ANT_link_posting& a) {
//		if (link_frequency == a.link_frequency)
//			return docid < a.docid;
//		return this->link_frequency > a.link_frequency;
//	}

//	bool operator<(const ANT_link_posting& a) {
//		return this->link_frequency < a.link_frequency;
//	}

	friend bool operator<(const ANT_link_posting& a, const ANT_link_posting& b) {
		return a.link_frequency < b.link_frequency;
	}

	friend bool operator>(const ANT_link_posting& a, const ANT_link_posting& b) {
		if (a.doc_link_frequency == b.doc_link_frequency)
			return a.docid < b.docid;
		return a.doc_link_frequency > b.doc_link_frequency;
	}

//	bool operator > (const ANT_link_posting *a) {
//		return this->link_frequency > a->link_frequency;
//	}
//
//	bool operator < (const ANT_link_posting *a) {
//		return this->link_frequency < a->link_frequency;
//	}
} ;

#endif /* ANT_LINK_POSTING_H_ */
