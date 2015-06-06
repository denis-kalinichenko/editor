#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define _SCL_SECURE_NO_WARNINGS
#include "File.h"

#include <stdio.h>
#include <sys\stat.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>

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


void File::setFileName2(char *_filename2) {
	if (_filename2 == filename) {
		cout << "Enter a NEW name for file!" << endl;
	}
	else {
		strcpy(filename2, _filename2);
	}
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
	setNumChars();
	setNumLines();
	setNumWords();
}

void File::setNumChars(void) {
	string line;
	int sum = 0;
	ifstream inData;
	inData.open(filename);

	while (!inData.eof())
	{
		getline(inData, line);

		int numofChars = line.length();
		for (unsigned int n = 0; n<line.length(); n++)
		{
			if (line.at(n) == ' ')
			{
				numofChars--;
			}
		}
		sum = numofChars + sum;
	}

	numChars = sum;
}
int File::getNumChars() {
	return numChars;
}

void File::setNumWords(void) {
    int spaces = 0;


	ifstream fin;
	fin.open(filename);
	while (fin.good()) // while file is open and reads without error or eof
	{
		if (32 == fin.get()) spaces++; // found space, increment counter
	}
	fin.close();

	numWords = spaces + numLines;
}

int File::getNumWords() {
	return numWords;
}

void File::setNumLines(void) {
	ifstream fin;
	fin.open(filename);

	string line;
	int counter = 1;
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			counter++;
		}
		fin.close();
		numLines = counter;
	}
}
int File::getNumLines() {
	return numLines;
}

void File::numberingLines(void) {
	ifstream fin;
	ofstream fout;
	fin.open(filename);
	fout.open(filename2);

	string line;
	int counter = 1;
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			fout << counter << ". " << line << endl;
			counter++;
		}
		fin.close();
		fout.close();
		success();
	}
}

void File::uppercase(void) {
	ifstream fin;
	ofstream fout;
	fin.open(filename);
	fout.open(filename2);

	string line;
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			string data = line;
			transform(data.begin(), data.end(), data.begin(), ::toupper);
			fout << data << endl;
		}
		fin.close();
		fout.close();
		success();
	}
}

void File::lowercase(void) {
	ifstream fin;
	ofstream fout;
	fin.open(filename);
	fout.open(filename2);

	string line;
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			string data = line;
			transform(data.begin(), data.end(), data.begin(), ::tolower);
			fout << data << endl;
		}
		fin.close();
		fout.close();
		success();
	}
}

void File::removeBlankLines(void) {
	ifstream fin;
	ofstream fout;
	fin.open(filename);
	fout.open(filename2);

	string line;
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			if (line != "") {
				fout << line << endl;
			}
		}
		fin.close();
		fout.close();
		success();
	}
}

void File::replaceTabsToSpaces(int spaces_c) {
	ifstream fin;
	ofstream fout;
	fin.open(filename);
	fout.open(filename2);

	string spaces = "";
	for (int i = 0; i < spaces_c; i++) {
		spaces += string(1, ' ');
	}

	if (fin.is_open())
	{
		char c;
		while (fin.get(c)) {
			if (c == '\t')
				fout << spaces;
			else
				fout << c;
		}
		fin.close();
		fout.close();
		success();
	}
}

void File::success(void) {
	system("cls");
	cout << "New file has been saved." << endl;
	exit(0);
}