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
 * topic.cpp
 *
 *  Created on: Aug 16, 2009
 *
 */

#include "topic.h"
#include "ant_link_parts.h"
#include "application_out.h"

//#include <libgen.h>
#include <stdio.h>
#include <string.h>

#define TOPIC_SIGNITURE_ID "	<topic file=\"%d\" name=\"%s\">\n"
#define TOPIC_SIGNITURE_ID_NAME "	<topic file=\"%s\" name=\"%s\">\n"

using namespace QLINK;

topic::topic(const char *topic_text)
{
	id_ = -1;
	strcpy(name_, "");
	strcpy(filename_, "");

//	set_filename(filename);
	set_content(topic_text);
}

topic::~topic()
{
//	if (content_)
//		delete [] content_;
}

void topic::set_filename(const char *filename)
{
	strcpy(filename_, filename);
}

void topic::set_content(const char *file)
{
	content_ = file;

	id_ = get_doc_id(file);
	get_doc_name((char *)file, name_);
	if (strlen(name_) <= 0) {
		char filename[1024];
		char *end = NULL;
		strcpy(filename, filename_);
		strcpy(name_, basename(filename));
		end = strchr(name_, '.');
		if (end != NULL)
			name_[end - name_] = '\0';
	}

}

void topic::print_header(application_out& aout)
{
	char buf[255];
	if (id_ > 0)
		sprintf(buf, TOPIC_SIGNITURE_ID, id_, name_);
	else
		sprintf(buf, TOPIC_SIGNITURE_ID_NAME, name_, name_);
//	else
//		fprintf(stderr, "Topic ID or ID_NAME error");
	aout << buf;
}

void topic::print_footer(application_out& aout)
{
	//puts("	</topic>");
	aout << "\t</topic>\n";
}
