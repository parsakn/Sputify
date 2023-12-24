
#include "SputifyCore.h"

SputifyCore::SputifyCore() {
    this->id_handler = new IdGenerator();
    this->logged_in_user = nullptr;
}

SputifyCore::~SputifyCore() {

}

void SputifyCore::signup(string& Username, string& Password, string& Mode) {
    if (find_username(Username)){
        throw invalid_argument("Bad Request");
    }
    int Id = this->id_handler->assign_id();
    accounts.push_back(new Account(Username,Password,Mode,Id));
    this->logged_in_user = accounts[accounts.size()-1];
    cout << "OK" << endl;
}

bool SputifyCore::find_username(string &Username) {
    bool isfound = false;
    for (int i = 0; i < this->accounts.size(); ++i) {
        if (accounts[i]->get_username() == Username){
            isfound = true;
            break;
        }
    }
    return isfound;
}

void SputifyCore::login(string &Username, string &Password) {
    if(logged_in_user == nullptr) {
        for (int i = 0; i < this->accounts.size(); ++i) {
            if (accounts[i]->get_username() == Username && accounts[i]->get_password() != Password) {
                throw invalid_argument("Permission Denied");
            }
            if (accounts[i]->get_username() == Username && accounts[i]->get_password() == Password) {
                this->logged_in_user = accounts[i];
                cout << "OK" << endl;
            }
        }
    }else{
        throw invalid_argument("Permission Denied");
    }
}

void SputifyCore::logout() {
    if (this->logged_in_user != nullptr) {
        this->logged_in_user = nullptr;
        cout << "OK" << endl;
    } else{
        throw invalid_argument("Permission Denied");
    }

}

