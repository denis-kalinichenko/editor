#define _CRT_SECURE_NO_WARNINGS
#include "File.h"

#include <stdio.h>
#include <sys\stat.h>
#include <stdlib.h>

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


void File::stats(void) {
	fstat(fileno(f), &buff);
}

int File::getNumChars() {
	return buff.st_size;
}

void File::info(void) {
	cout << "info " << buff.st_size << endl;
}