#ifndef SPUTIFY_SPUTIFYCORE_H
#define SPUTIFY_SPUTIFYCORE_H

#include "Manual.h"
#include "Account.h"
#include "iostream"
#include "vector"
#include "IdGenerator.h"

class SputifyCore {
private:
    vector<Account*> accounts;
    Account* logged_in_user;
    IdGenerator* id_handler;
    bool find_username(string &Username);



public:
    SputifyCore();
    ~SputifyCore();

    void signup(string& Username, string& Password, string& Mode);
    void login(string& Username, string& Password);
    void logout();

};


#endif //SPUTIFY_SPUTIFYCORE_H
