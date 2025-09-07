#pragma once
#include "Contact.h"
#include <cstdio>

class PhoneBook {
private:
    Contact* contacts[100];
    int count;
public:
    ~PhoneBook();

    void AddContact(Contact* c);
    void DeleteContact(const char* n, const char* s, const char* p);
    Contact* FindContact(const char* n, const char* s, const char* p);
    void PrintAllContacts();
    void SaveInfoInFile();
    
};
