#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class File
{
private:
	char filename[50];
	FILE *f;
	struct stat buff;
	int numLines = 0;
public:
	File(char *_filename);
	~File();

	void setFileName(char *_filename);

	void open(void);

	void stats(void);

	int getNumChars();

	void setNumLines(void);
	int getNumLines();

	void info(void);

};