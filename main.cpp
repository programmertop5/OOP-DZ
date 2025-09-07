#include "PhoneBook.h"
#include "Contact.h"
#include <iostream>
using namespace std;

int main() {
    PhoneBook myPhoneBook;
    int choice = -1;

    do {
        cout << "\n--- Phone Book Menu ---\n";
        cout << "1. Add contact\n2. Delete contact\n3. Find contact\n4. Show all contacts\n5. Save to file\n0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            char name[100], surname[100], parent[100], info[250];
            int call, work, mobile;

            cout << "Enter Name: "; 
            cin.getline(name, 100);
            cout << "Enter Surname: ";
            cin.getline(surname, 100);
            cout << "Enter Parent Name: "; 
            cin.getline(parent, 100);
            cout << "Enter Call: "; 
            cin >> call;
            cout << "Enter Work: ";
            cin >> work;
            cout << "Enter Mobile: "; 
            cin >> mobile; cin.ignore();
            cout << "Enter Additional Info: "; 
            cin.getline(info, 250);

            Contact* c = new Contact(name, surname, parent, call, work, mobile, info);
            myPhoneBook.AddContact(c);
            system("cls");
            break;
        }
        case 2: {
            char name[100], surname[100], parent[100];
            cout << "Enter Name to delete: "; 
            cin.getline(name, 100);
            cout << "Enter Surname: "; 
            cin.getline(surname, 100);
            cout << "Enter Parent Name: "; 
            cin.getline(parent, 100);
            myPhoneBook.DeleteContact(name, surname, parent);
            system("cls");
            break;
        }
        case 3: {
            char name[100], surname[100], parent[100];
            cout << "Enter Name to find: "; 
            cin.getline(name, 100);
            cout << "Enter Surname: "; 
            cin.getline(surname, 100);
            cout << "Enter Parent Name: "; 
            cin.getline(parent, 100);
            Contact* f = myPhoneBook.FindContact(name, surname, parent);
            if (f) {
                f->PrintContact();
            }
            else {
                cout << "Contact not found!\n";
            }
            system("cls");
            break;
        }
        case 4:
            myPhoneBook.PrintAllContacts();
            system("cls");
            break;
        case 5:
            myPhoneBook.SaveInfoInFile();
            system("cls");
            break;
        case 0:
            cout << "Exit...\n"; 
            break;
        default:
            cout << "Invalid choice!\n"; 
            break;
        }

    } while (choice != 0);

    return 0;
}
