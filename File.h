#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class File
{
private:
	char filename[50];
	FILE *f;
public:
	File(char *_filename);
	~File();

	void info(void);

	void read(void);
};