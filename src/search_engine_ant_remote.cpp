/*
 * search_engine_ant_remote.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: monfee
 */

#include "search_engine_ant_remote.h"

#include <stddef.h>
#include <string.h>
#include "str.h"

/*
	BETWEEN()
	---------
	written by Andrew Trotman
*/
char *between(const char *source, const char *open_tag, const char *close_tag)
{
char *start,*finish;

if ((start = strstr((char *)source, (char *)open_tag)) == NULL)
	return NULL;

start += strlen(open_tag);

if ((finish = strstr(start, close_tag)) == NULL)
	return NULL;

return strnnew(start, finish - start);
}

search_engine_ant_remote::search_engine_ant_remote() {
	if (!socket.open((char *)"localhost:8088"))
		{
		fprintf(stderr, "Cannot open socket");
		exit(-1);
		}
}

search_engine_ant_remote::~search_engine_ant_remote() {
}

long search_engine_ant_remote::search(const char* query,
		std::vector<std::string> *ids, int how_many_needed) {
	int decoded;
	long hits, current, valid, atire_found = 0, time_taken = 0, antid;
	long long bytes;
	char *start, *ch;
	char *filename, *title, *snippet;

	const char *result = socket.search((char *)query, 1,10);

	if (result == NULL || strstr(result, "<ATIREerror>") != NULL)
		{
		fprintf(stderr, "Communications Error in search request");
		return 0;
		}

	atire_found = hits = atol(between(result, "<numhits>", "</numhits>"));

	if (hits > how_many_needed)
		hits = how_many_needed;

	start = (char *)result;
	for (current = 0; current < hits; current++)
		{
		start = strstr(start, "<hit>");
		filename = between(start, "<name>", "</name>");
		ids->push_back(filename);
		start++;
		}
	return 1;
}


