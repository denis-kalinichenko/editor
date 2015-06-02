#include <iostream>
#include <string.h>

using namespace std;

/* Filtr tekstowy dla plików tekstowych */

#include "File.h"

int main(int argc, char** argv) {

	char new_file_name[50];

	cout << "Enter a name of file in current directory: ";
	cin >> new_file_name;

	File TextFile(new_file_name);

	TextFile.info();

	system("pause");
	return 0;
}
