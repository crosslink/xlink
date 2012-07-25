#include <string>
#include <iostream>
#include "../utils/fs.h"
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " file" << std::endl;
		return 0;
	}  
	
	FILESYSTEM::File<string> dir(argv[1]);
	vector<string> files;
	int count;
	if ((count = dir.list(files)) > 0) {
		for (int i=0; i<count; i++)
			cout << files[i] << endl;
	} else if (count < 0){
		cerr << dir.name() <<  ": Not a directory" << endl;
	} else
		cerr <<  "No files found" << endl;
	
	return 1;
}
