#include "Data.h"

Data::Data(Stack<string>* newDates, int newNumAbsences, int newRecordNumber, int newID, string newName, string newEmail,
	string newCredits, string newMajor, string newLevel)
{
	absenceDates = newDates;
	numAbsences = newNumAbsences;
	recordNumber = newRecordNumber;
	ID = newID;
	name = newName;
	email = newEmail;
	credits = newCredits;
	major = newMajor;
	level = newLevel;
}

Data::~Data()
{
	absenceDates->~Stack();
}

Stack<string>* Data::getAbsenceDates() const
{
	return absenceDates;
}

int Data::getNumOfAbsences() const
{
	return numAbsences;
}

int Data::getRecord() const
{
	return recordNumber;
}

int Data::getID() const
{
	return ID;
}

string Data::getName() const
{
	return name;
}

string Data::getEmail() const
{
	return email;
}

string Data::getCredits() const
{
	return credits;
}

string Data::getMajor() const
{
	return major;
}

string Data::getLevel() const
{
	return level;
}

/*Setters*/
void Data::setAbsenceDates(Stack<string>* newDates)
{
	absenceDates = newDates;
}

void Data::setNumOfAbsences(int newNum)
{
	this->numAbsences = newNum;
}

void Data::setRecord(int newRecord)
{
	recordNumber = newRecord;
}

void Data::setID(int newID)
{
	ID = newID;
}

void Data::setName(string newName)
{
	name = newName;
}

void Data::setEmail(string newEmail)
{
	email = newEmail;
}

void Data::setCredits(string newCredits)
{
	credits = newCredits;
}

void Data::setMajor(string newMajor)
{
	major = newMajor;
}

void Data::setLevel(string newLevel)
{
	level = newLevel;
}

/*Overloaded operator*/
Data& Data::operator=(const Data& rhs)
{
	numAbsences = rhs.getNumOfAbsences();
	recordNumber = rhs.getRecord();
	ID = rhs.getID();
	name = rhs.getName();
	email = rhs.getEmail();
	credits = rhs.getCredits();
	major = rhs.getMajor();
	level = rhs.getLevel();
	absenceDates = rhs.getAbsenceDates(); //calls the deep copy operator we made in stack.h

	return *this;
}

fstream& operator<<(fstream& lhs, Data& rhs)
{
	lhs << rhs.getRecord() << endl;
	lhs << rhs.getID() << endl;
	lhs << rhs.getName() << endl;
	lhs << rhs.getEmail() << endl;
	lhs << rhs.getAbsenceDates() << endl;
	lhs << rhs.getNumOfAbsences() << endl;
	lhs << rhs.getMajor() << endl;
	lhs << rhs.getCredits() << endl;
	lhs << rhs.getLevel() << endl;

	return lhs;
}

fstream& operator>>(fstream& lhs, Data& rhs)
{
	string temp;
	
	lhs >> temp;
	rhs.setRecord(stoi(temp));

	lhs >> temp;
	rhs.setID(stoi(temp));

	lhs >> temp;
	rhs.setName(temp);

	lhs >> temp;
	rhs.setEmail(temp);

	
	return lhs;
}
