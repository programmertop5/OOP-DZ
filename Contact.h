#pragma once
class Contact
{
private:
    char* name;
    char* surname;
    char* parentname;
    
    int callnumber;
    int worknumber;
    int mobilephone;
    
    char information[250];
public:
    Contact();
    Contact(const char* n, const char* s, const char* p, int callnumber_, int worknumber_,
    int mobilephone_, const char* information_);
    ~Contact();

    void PrintContact();

    void SetName(const char*value);
    void SetSurname(const char*value);
    void SetParentName(const char*value);
    void SetCallNumber(int);
    void SetWorkNumber(int);
    void SetMobilePhone(int);
    void SetInformation(const char*value);

    char* getName();
    char* getSurname();
    char* getParentName();
    int getCallNumber();
    int getWorkNumber();
    int getMobilePhone();
    char* getInformation();





};

