/*
 * wikify.cpp
 *
 *  Created on: 14/06/2013
 *      Author: monfee
 */

#include "../src/wikification.h"
#include "../src/sys_file.h"

#include <iostream>
#include <string>

using namespace std;
using namespace QLINK;

static void usage(const char *program) {
	cerr << program << ": anchors_file page" << endl;
	exit(-1);
}

int main(int argc, char **argv)
{
	if (argc < 3)
		usage(argv[0]);
	const char *xml_file = sys_file::read_entire_file(argv[1]);
	const char *page = sys_file::read_entire_file(argv[2]);

	string wikified_page = QLINK::wikification::linkify(xml_file, page);

	cout << wikified_page;

	delete [] xml_file;
	delete [] page;
	return 1;
}

