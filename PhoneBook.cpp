#include "PhoneBook.h"
#include <iostream>
#include <cstring>
using namespace std;

PhoneBook::~PhoneBook() {
    for (int i = 0; i < count; i++)
        delete contacts[i];
}

void PhoneBook::AddContact(Contact* c) {
    if (count < 100) {
        contacts[count++] = c;
    }
    else {
        cout << "PhoneBook is full!" << endl;
    }
}

void PhoneBook::DeleteContact(const char* n, const char* s, const char* p) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i]->getName(), n) == 0 &&
            strcmp(contacts[i]->getSurname(), s) == 0 &&
            strcmp(contacts[i]->getParentName(), p) == 0) {

            delete contacts[i];
            contacts[i] = contacts[count - 1];
            contacts[count - 1] = nullptr;
            count--;
            cout << "Contact deleted!\n";
            return;
        }
    }
    cout << "Contact not found!\n";
}

Contact* PhoneBook::FindContact(const char* n, const char* s, const char* p) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i]->getName(), n) == 0 &&
            strcmp(contacts[i]->getSurname(), s) == 0 &&
            strcmp(contacts[i]->getParentName(), p) == 0) {
            return contacts[i];
        }
    }
    return nullptr;
}

void PhoneBook::PrintAllContacts() {
    if (count == 0) {
        cout << "No contacts in the phone book." << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "Contact " << i + 1 << ":" << endl;
        contacts[i]->PrintContact();
        cout << "----------------------" << endl;
    }
}

void PhoneBook::SaveInfoInFile() {
    FILE* f = fopen("phonebook.txt", "w");
    if (!f) {
        cout << "Cannot open file!" << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(f, "Contact %d:\n", i + 1);
        fprintf(f, "Name: %s\n", contacts[i]->getName());
        fprintf(f, "Surname: %s\n", contacts[i]->getSurname());
        fprintf(f, "Parent: %s\n", contacts[i]->getParentName());
        fprintf(f, "Call: %d\n", contacts[i]->getCallNumber());
        fprintf(f, "Work: %d\n", contacts[i]->getWorkNumber());
        fprintf(f, "Mobile: %d\n", contacts[i]->getMobilePhone());
        fprintf(f, "Info: %s\n", contacts[i]->getInformation());
        fprintf(f, "----------------------\n");
    }
    fclose(f);
    cout << "Contacts saved!\n";
}
