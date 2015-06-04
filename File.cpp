#define _CRT_SECURE_NO_WARNINGS
#include "File.h"


File::File(char *_filename)
{
	setFileName(_filename);
}


File::~File()
{
	fclose(f);
}

void File::setFileName(char *_filename) {
	strcpy(filename, _filename);
}

void File::open(void) {
	if ((f = fopen(filename, "r")) == NULL) {
		printf("Cannot open file.\n");
		system("pause");
		exit(1);
	}
}

void File::info(void) {
	cout << "info " << filename << endl;
}

void File::read(void) {
	cout << "info " << filename << endl;
}