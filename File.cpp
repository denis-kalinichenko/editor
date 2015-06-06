#define _CRT_SECURE_NO_WARNINGS
#include "File.h"

#include <stdio.h>
#include <sys\stat.h>
#include <stdlib.h>
#include <fstream>
#include <string>

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
	int ch = 0;
	unsigned int number_of_lines = 0;
	while (EOF != (ch = getc(f)))
		if ('\n' == ch)
			++number_of_lines;
	++number_of_lines;
	numLines = number_of_lines;
}
int File::getNumLines() {
	return numLines;
}

void File::numberingLines(void) {
	ifstream fin;

	ofstream fout;

	fin.open(filename);

	fout.open(filename2);

	char n;
	int counter = 1;
	fin.get(n);

	while (!fin.eof())
	{
		if (n == '\n')
		{
			fin.get(n);
			fout << endl << counter << ". " << n;
			counter++;
		}
		else {
			if (counter == 1) {
				fin.get(n);
				fout << counter << ". " << n;
				counter++;
			}
			else {
				fout << n;
			}
		}
		fin.get(n);
	}
	fin.close();
	fout.close();
}

void File::uppercase(void) {
	ifstream fin;

	ofstream fout;

	fin.open(filename);

	fout.open(filename2);

	char n;
	fin.get(n);

	while (!fin.eof())
	{
		if (n == '.')
		{
			fin.get(n);
			fout << static_cast<char>(toupper(n));
		}
		else {
			fout << static_cast<char>(toupper(n));
		}
		fin.get(n);
	}
	fin.close();
	fout.close();
}

void File::lowercase(void) {
	ifstream fin;

	ofstream fout;

	fin.open(filename);

	fout.open(filename2);

	char n;
	fin.get(n);

	while (!fin.eof())
	{
		if (n == '.')
		{
			fin.get(n);
			fout << static_cast<char>(tolower(n));
		}
		else {
			fout << static_cast<char>(tolower(n));
		}
		fin.get(n);
	}
	fin.close();
	fout.close();
}

void File::info(void) {
	cout << "info " << buff.st_size << endl;
}