#pragma once
#include "Stack.h"
class Data
{
private:
	Stack<string>* absenceDates;
	int numAbsences;
	int recordNumber;
	int ID;
	string name;
	string email;
	string credits;
	string major;
	string level;

public:
	Data(Stack<string>* newDates = {}, int newNumAbsences = 0, int newRecordNumber = 0, int newID = 0, string newName = "", string newEmail = "", 
		string newCredits = "", string newMajor = "", string newLevel = "");
	~Data();

	/*Getters*/
	Stack<string>* getAbsenceDates() const;
	int getNumOfAbsences() const;
	int getRecord() const;
	int getID() const;
	string getName() const;
	string getEmail() const;
	string getCredits() const;
	string getMajor() const;
	string getLevel() const;

	/*Setters*/
	void setAbsenceDates(Stack<string>* newDates);
	void setNumOfAbsences(int newNum);
	void setRecord(int newRecord);
	void setID(int newID);
	void setName(string newName);
	void setEmail(string newEmail);
	void setCredits(string newCredits);
	void setMajor(string newMajor);
	void setLevel(string newLevel);

	/*Overloaded copy assignment operator*/
	Data& operator=(const Data& rhs);
};

fstream& operator<<(fstream& lhs, Data& rhs);
fstream& operator>>(fstream& lhs, Data& rhs);
