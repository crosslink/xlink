#include <stdlib.h>

#include <iostream>

#include "../src/urlcode.h"

using namespace std;

static void usage(const char *program) {
	cerr << program << ": url" << endl;
	exit(-1);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
		usage(argv[0]);

	cout << url_encode(argv[1]) << endl;

	return 1;
}
