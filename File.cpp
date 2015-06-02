#define _CRT_SECURE_NO_WARNINGS
#include "File.h"


File::File(char *_filename)
{
	strcpy(filename, _filename);
	if ((f = fopen(filename, "r")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}
}


File::~File()
{
}

void File::info(void) {
	cout << "info " << filename << endl;
}

void File::read(void) {
	cout << "info " << filename << endl;
}