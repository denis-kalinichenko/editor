#pragma once
#include <iostream>
#include <string.h>
#include <fstream> 
using namespace std; //TODO delete this

class File
{
private:
	char filename[50];
	FILE *f;
	struct stat buff;
	int numChars = 0;
	int numWords = 0;
	int numLines = 0;
public:
	File(char *_filename);
	~File();

	void setFileName(char *_filename);

	void open(void);

	void stats(void);

	void setNumChars(void);
	int getNumChars();

	void setNumWords(void);
	int getNumWords();

	void setNumLines(void);
	int getNumLines();

	void info(void);

};