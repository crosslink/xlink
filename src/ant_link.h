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
 * ant_link.h
 *
 *      Author: Andrew Trotman @ Otago University
 */

#ifndef ANT_LINK_H_
#define ANT_LINK_H_

#ifdef REMOVE_ORPHAN_LINKS
	#define ADD_ORPHAN_LINKS 1
	#define SUBTRACT_ORPHAN_LINKS (-1)
#endif

#ifndef FALSE
	#define FALSE 0
#endif
#ifndef TRUE
	#define TRUE (!FALSE)
#endif

#ifndef _MSC_VER
#define _strdup strdup
#endif

#define MODE_NO_4_DIGIT_NUMBERS 1

//#ifdef INEX_ARCHIVE
//	#define COLLECTION_LINK_TAG_NAME "collectionlink"
//	#define TOPIC_SIGNITURE "<topic file=\"%d.xml\" name=\"%s\"><outgoing>\n"
//#else
//	#define COLLECTION_LINK_TAG_NAME "link"
//	#define TOPIC_SIGNITURE "<topic file=\"%d\" name=\"%s\"><outgoing>\n"
//#endif

class ANT_link_term;

class ANT_link
{
public:
	char *place_in_file;
	long offset;                    // could be the bep for incoming link, or the offset of the anchor for outgoing link
	char *term;
	double gamma;
	long target_document;  			// could either source or target document,
									// if for incoming link target document is the source document linked to current file
	ANT_link_term *link_term;
} ;

#endif /* ANT_LINK_H_ */
