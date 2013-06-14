/*
 * wikify.cpp
 *
 *  Created on: 14/06/2013
 *      Author: monfee
 */

#include <iostream>

using namespace std;

static void usage(const char *program) {
	cerr << program << ": anchors_file page" << endl;
	exit(-1);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
		usage(argv[0]);

//	cout << url_encode(argv[1]) << endl;

	return 1;
}

