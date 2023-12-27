#ifndef SPUTIFY_SPUTIFYCORE_H
#define SPUTIFY_SPUTIFYCORE_H

#include "Manual.h"
#include "Account.h"
#include "iostream"
#include "vector"
#include "IdGenerator.h"
#include "Song.h"
#include "User.h"
#include "Artist.h"

class SputifyCore {
private:
    vector<Account*> accounts;
    vector<Song*> songs;
    Account* logged_in_user;
    IdGenerator* account_id_handler;
    IdGenerator* songs_id_handler;
    bool find_username(string &Username);



public:
    SputifyCore();
    ~SputifyCore();

    void signup(string& Username, string& Password, string& Mode);
    void add_music(string& Title, string& Path, string& Year,string& Tags,string& Duration);
    void login(string& Username, string& Password);
    void logout();
    void show_musics();
    void show_specific_music(int Id);
    void print_specific_music(Song* music);
    void print_songs();
    void show_users();
    void print_users();

};


#endif //SPUTIFY_SPUTIFYCORE_H
