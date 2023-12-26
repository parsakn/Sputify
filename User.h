
#ifndef SPUTIFY_USER_H
#define SPUTIFY_USER_H

#include "Account.h"
#include "Playlist.h"
#include "iostream"
#include "vector"
#include "Manual.h"

class User : public Account{
private:

public:

    User(string& User_Name, string& Password, string& User_mode,int& Id);
    ~User() = default;

    virtual void add_song(string& Title,string& Path,string& Year,string& Tags,string& Duration) override;
};


#endif //SPUTIFY_USER_H
