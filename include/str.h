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
 * str.h
 *
 *  Created on: Oct 6, 2009
 *      Adapted from code of Andrew Trotman and others
 */

#ifndef STR_H_
#define STR_H_

/*
 * This is evil code
 */
inline const char *strbck(const char *source, const char* start)
{
	while (start != source && !isspace(*start))
		--start;

	if (isspace(*start))
		start++;
	return start;
}

/*
 * This is evil code
 */
inline const char *strfwd(const char *end, const char* start)
{
	while (start < end && !isspace(*start))
		++start;

//	if (isspace(*start))
//		start--;
	return start;
}

/*
	STRNNEW()
	---------
*/
inline char *strnnew(const char *str, long long len)
{
char *new_str;

return (*((new_str = strncpy(new char [(size_t)(len + 1)], str, (size_t)len)) + len) = '\0'), new_str;
}

#endif /* STR_H_ */
