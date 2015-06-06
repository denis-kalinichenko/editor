#include <iostream>
#include <istream>
#include <fstream>
#include <string.h>
#include <string>


using namespace std;

#include "File.h"

void showOptions() {
	string options[] = {
		"Zliczanie znakow, slow i wierszy",
		"Numerowanie wierszy pliku",
		"Usuwanie pustych wierszy",
		"Zamiana malych liter na duze",
		"Zamiana duzych liter na male",
		"Zamiana znakow tabulacji na okreslona liczbe spacji",
		"Zliczanie krotnosci wystapienia podanego ciagu znakow",
		"Zamiana podanego ciagu znakow na inny podany ciag",
		"Usuniecie z pliku podanego ciagu znakow",
		"Wypisanie wierszy (oraz ich numerow) zawierajacych podany ciag znakow",
		"Wypisanie n poczatkowych wierszy pliku",
		"Wypisanie n koncowych wierszy pliku",
		"konwersja polskich znakow (dla standardow kodowania ISO-8859-2, Windows-1250, Unicode)"
	};

	int size = sizeof(options) / sizeof(string);

	for (int i = 0; i < size; i++) {
		cout << i << ". " << options[i] << endl;
	}
}

int main(int argc, char** argv) {


	char new_file_name[50];

	cout << "Enter a name of file in current directory: ";
	cin >> new_file_name;

	File TextFile(new_file_name);

	char new_filename[50];
	cout << "Enter name of new file: ";
	cin >> new_filename;
	TextFile.setFileName2(new_filename);


	TextFile.open();
	TextFile.stats();

	
	showOptions();

	int action;

	cin >> action;


	if (action > 13) {
		system("cls");
		cout << "Please, choose from list" << endl;
		system("pause");
		exit(1);
	}

	string keyword;

	switch (action)
	{
	case 0:
		cout << "Zliczanie znakow (1), slow (2) i wierszy (3): ";
		int action_count;
		cin >> action_count;
		switch (action_count)
		{
		case 1:
			cout << "Znakow: " << TextFile.getNumChars() << endl;
			break;
		case 2:
			cout << "Slow: " << TextFile.getNumWords() << endl;
			break;
		case 3:
			cout << "Wierzy: " << TextFile.getNumLines() << endl;
			break;
		default:
			break;
		}

		break;
	case 1:
		TextFile.numberingLines();
		break;
	case 2:
		TextFile.removeBlankLines();
		break;
	case 3:
		TextFile.uppercase();
		break;
	case 4:
		TextFile.lowercase();
		break;
	case 5:
		int spaces;
		cout << "Podaj ilosc spacji: ";
		cin >> spaces;
		TextFile.replaceTabsToSpaces(spaces);
		break;
	case 6:
		cout << "Podaj ciag znakow: ";
		cin >> keyword;
		int times;
		times = TextFile.countTimes(keyword);
		cout << "Znaleziono " << times << " razy." << endl;
		break;
	default:
		break;
	}


	system("pause");
	return 0;
}

