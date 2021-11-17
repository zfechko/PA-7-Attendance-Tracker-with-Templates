#include "Menu.h"

Menu::Menu()
{
	//implicit
}

Menu::~Menu()
{
	//implicit
}

void Menu::displayMenu()
{
	cout << "Please type the number of what you would like to do" << endl;
	cout << "1] Import course list" << endl;
	cout << "2] Load master list" << endl;
	cout << "3] Store master list to text file" << endl;
	cout << "4] Mark Student Absences" << endl;
	cout << "5] Edit Student Absences" << endl;
	cout << "6] Generate report" << endl;
	cout << "7] Exit" << endl;
}

int Menu::getChoice()
{
	int choice = 0;
	cout << "Type a number: ";
	cin >> choice;

	return choice;
}

void Menu::displayRecordMenu()
{
	cout << "Enter the number of the type of record you would like to generate" << endl;
	cout << "1] Generate a report for all students" << endl;
	cout << "2] Generate a report for a specific student" << endl;
}

void Menu::exitApp()
{
	cout << "see you later!" << endl;
	exit(0);
}