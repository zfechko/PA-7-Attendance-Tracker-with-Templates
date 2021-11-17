#pragma once
#include "List.h"
#include "Stack.h"
#include "Node.h"
#include "Data.h"
#include "Menu.h"

class Application
{
private:
	List<Data> masterList;
	fstream classList;
	fstream masterStorage;
	Menu menu;

public:
	void runApp();
	void displayMenu();
	int getChoice();
	void importList();
	bool storeMaster();
	bool loadMaster();
	void markAbsences();
	void generateReport();
};

