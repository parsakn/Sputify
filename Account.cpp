#include "Account.h"

Account::Account(string User_Name, string Password, string User_mode, int Id) {
    this->username = User_Name;
    this->password = Password;
    this->user_mode = User_mode;
    this->id = Id;
}

Account::~Account() {

}

string Account::get_username() {
    return this->username;
}

string Account::get_password() {
    return this->password;
}

string Account::get_mode() {
    return this->user_mode;
}

