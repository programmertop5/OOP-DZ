#include "Contact.h"
#include <iostream>
using namespace std;


Contact::Contact()
{
	cout << "Constructor worked!" << endl;
	name = new char[100];
	surname = new char[100];
	parentname = new char[100];
	strcpy_s(name, 100, "Karina");
	strcpy_s(surname, 100, "Matvienko");
	strcpy_s(parentname, 100, "Oleksandrivna");
	callnumber = 380983750144;
	worknumber = 380923470381;
	mobilephone = 380932948819;
	strcpy_s(information, 250, "No information");
}


Contact::Contact(const char* n, const char* s, const char* p, int callnumber_, int worknumber_, int mobilephone_, const char* information_)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);

	surname = new char[strlen(s) + 1];
	strcpy_s(surname, strlen(s) + 1, s);

	parentname = new char[strlen(p) + 1];
	strcpy_s(parentname, strlen(p) + 1, p);

	callnumber = callnumber_;
	worknumber = worknumber_;
	mobilephone = mobilephone_;

	strcpy_s(information, sizeof(information), information);
}

Contact::~Contact()
{
	delete[]name;
	delete[]surname;
	delete[]parentname;
}


void Contact::PrintContact()
{
	cout << "Name - > " << name << endl;
	cout << "Surname - >" << surname << endl;
	cout << "Parentname - > " << parentname << endl;
	cout << "Callnumber - > " << callnumber << endl;
	cout << "Worknumber - > " << worknumber << endl;
	cout << "Mobulenumber - > " << mobilephone << endl;
	cout << "Information - > " << information << endl;

}

void Contact::SetName(const char* value)
{
	if ((strlen)(value) < 1) {
		cout << "Error!Name must be greater than 0" << endl;
		return;
	}
	strcpy_s(name, 100, value);
}
void Contact::SetSurname(const char* value)
{
	if ((strlen)(value) < 1) {
		cout << "Error!Surname must be greater than 0" << endl;
		return;
	}
	strcpy_s(surname, 100, value);
}
void Contact::SetParentName(const char* value)
{
	if ((strlen)(value) < 1) {
		cout << "Error!Parent name  must be greater than 0" << endl;
		return;
	}
	strcpy_s(parentname, 100, value);
}

void Contact::SetCallNumber(int value)
{
	if (value < 1) {
		cout << "Error!Call number must be greater than 0" << endl;
		return;
	}
	callnumber = value;
}

void Contact::SetWorkNumber(int value)
{
	if (value < 1) {
		cout << "Error!Work number must be greater than 0" << endl;
		return;
	}
	worknumber = value;
}

void Contact::SetMobilePhone(int value)
{
	if (value < 1) {
		cout << "Error!Mobile number must be greater than 0" << endl;
		return;
	}
	mobilephone = value;
}

void Contact::SetInformation(const char* value)
{
	if ((strlen)(value) < 1){
		cout << "Error!Information  must be greater than 0" << endl;
		return;
	}
	strcpy_s(information, sizeof(information), value);
}


char* Contact::getName()
{
	return name;
}

char* Contact::getSurname()
{
	return surname;
}

char* Contact::getParentName()
{ 
	return parentname;
}

int Contact::getCallNumber()
{
	return callnumber;
}

int Contact::getWorkNumber()
{
	return worknumber;

}

int Contact::getMobilePhone()
{
	return mobilephone;

}
char* Contact::getInformation()
{
	return information;

}



	

