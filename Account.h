#ifndef SPUTIFY_ACCOUNT_H
#define SPUTIFY_ACCOUNT_H
#include "iostream"
#include "string"
#include "Manual.h"

using namespace std;

class Account {
protected:
    string username;
    string password;
    string user_mode;
    int id;


public:
    Account(string User_Name, string Password, string User_mode,int Id);
    ~Account();

    virtual void add_song(string& Title,string& Path,string& Year,string& Tags,string& Duration) = 0;
    string get_username();
    string get_password();
    string get_mode();
};


#endif //SPUTIFY_ACCOUNT_H
