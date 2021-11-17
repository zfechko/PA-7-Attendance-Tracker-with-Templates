#pragma once
#include "libraries.h"
class Menu
{
private:
	//no private data members
public:
	Menu();
	~Menu();

	void displayMenu();
	int getChoice();
	void displayRecordMenu();
	void exitApp();
};

