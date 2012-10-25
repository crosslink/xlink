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
