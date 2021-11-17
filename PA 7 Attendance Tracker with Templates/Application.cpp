#include "Application.h"

void Application::runApp()
{
	int menuChoice = 0;
	while (menuChoice != 7)
	{
		system("cls");
		menu.displayMenu();
		menuChoice = menu.getChoice();
		switch (menuChoice)
		{
		case 1:
			//import list from csv
			importList();
			break;
		case 2:
			//load list from master text file
			break;
		case 3:
			//store master to text file
			storeMaster();
			break;
		case 4:
			//mark student absences
			markAbsences();
			break;
		case 5:
			//edit absences
			break;
		case 6:
			//generate report
			generateReport();
			break;
		case 7:
			//exit
			break;
		default:
			system("cls");
			cout << "Invalid option, try again" << endl;
			menuChoice = 0;
		}
	}
}

void Application::displayMenu()
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

int Application::getChoice()
{
	int choice = 0;
	cout << "Type a number: ";
	cin >> choice;
	return choice;
}

void Application::importList()
{
	this->classList.open("classList.csv", ios::in);
	string line = "";
	getline(classList, line); //skipping the first line of the csv which is info
	while (getline(classList, line, ',')) //getline function with a delimiter
	{
		/*Setting these variables to empty in the beginning of the loop so we can use the constructor for Data*/
		int record = 0, ID = 0;
		string name = "", email = "", credits = "", major = "", level = "";
		char ignoreComma = '\0'; //this is for dealing with the way names in the csv are structured

		record = atoi(line.c_str());

		getline(classList, line, ',');
		ID = atoi(line.c_str());

		classList.get(ignoreComma);
		getline(classList, line, ',');
		name = line;
		getline(classList, line, '"');
		name += ',';
		name += line; //appending the other parts of the name to the line
		classList.get(ignoreComma);

		getline(classList, line, ',');
		email = line;

		getline(classList, line, ',');
		credits = line;

		getline(classList, line, ',');
		major = line;

		getline(classList, line, ',');
		level = line;

		Stack<string>* newStack = new Stack<string>();
		Data* newData = new Data(newStack, 0, record, ID, name, email, credits, major, level);
		masterList.insertAtFront(newData);
	}
	classList.close();
}

bool Application::storeMaster()
{
	bool success = false;
	masterStorage.open("masterList.txt", ios::out);
	Node<Data>* pMem = masterList.getHeadPtr();
	if (masterStorage.is_open())
	{
		success = true;
		while (pMem != nullptr)
		{
			masterStorage << (*pMem->getData());
			if (pMem->getNext() != nullptr)
			{
				masterStorage << endl; //helps organize the master list
			}
			pMem = pMem->getNext();
		}
		masterStorage.close();
		success = true;
	}
	return success;
}

bool Application::loadMaster()
{
	bool success = false;
	masterStorage.open("masterList.txt", ios::in);
	return success;
}

void Application::markAbsences()
{
	Node<Data>* pNode = masterList.getHeadPtr();
	string date = "";
	time_t t = time(0);   // get time now

	struct tm* now = localtime(&t);
	date = std::to_string(now->tm_mon + 1) + "." + std::to_string(now->tm_mday) + std::to_string(now->tm_year);

	if (pNode != nullptr)
	{
		while (pNode != nullptr)
		{
			char absent = '\0';
			cout << "Was " << pNode->getData()->getName() << " absent today? [y/n]" << endl;
			while (absent != 'y' || absent != 'Y' || absent != 'n' || absent != 'N')
			{
				cin >> absent;
			}
			if (absent == 'y' || absent == 'Y')
			{
				pNode->getData()->setNumOfAbsences(pNode->getData()->getNumOfAbsences() + 1);
				pNode->getData()->getAbsenceDates()->push(date);
			}
			pNode = pNode->getNext();
		}
		
	}
}

void Application::generateReport()
{
	int choice = 0;
	menu.displayRecordMenu();
	Node<Data>* pNode = masterList.getHeadPtr();

	while (choice < 1 || choice > 2)
	{
		choice = getChoice();
	}
	
	if (choice == 1 && pNode != nullptr)
	{
		cout << "Student's and their last recorded absence" << endl;
		while (pNode != nullptr)
		{
			cout << pNode->getData()->getName() << " was last absent on ";
			if (pNode->getData()->getAbsenceDates()->isEmpty())
			{
				cout << "never" << endl;
			}
			else
			{
				cout << pNode->getData()->getAbsenceDates()->peek() << endl;
			}
			pNode = pNode->getNext();
		}
	}

	if (choice == 2 && pNode != nullptr)
	{
		int absenceFilter = 0;
		cout << "What is the minimum number of absences you would like to sort by? ";
		while (absenceFilter <= 0) //buffer to protect against invalid values
		{
			cin >> absenceFilter;
		}
		while (pNode != nullptr)
		{
			if (pNode->getData()->getNumOfAbsences() >= absenceFilter)
			{
				cout << pNode->getData()->getName() << " has been absent " << pNode->getData()->getNumOfAbsences() << " times" << endl;
			}
			pNode = pNode->getNext();
		}
	}
}