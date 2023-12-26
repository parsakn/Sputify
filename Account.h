#ifndef SPUTIFY_ACCOUNT_H
#define SPUTIFY_ACCOUNT_H
#include "iostream"
#include "string"
#include "Manual.h"
#include "vector"
#include "Song.h"
#include "Playlist.h"

using namespace std;

class Account {
protected:
    string username;
    string password;
    string user_mode;
    int id;

    vector<Song*> songs;
    vector<Playlist*> playlists;

public:
    Account(string& User_Name, string& Password, string& User_mode,int& Id);
    ~Account();


    string get_username();
    string get_password();
    string get_mode();
    Song* get_last_song();
//    int get_id() const;
//    int get_songs_count();
//    int get_playlists_count();

    virtual void add_song(string& Title,string& Path,string& Year,string& Tags,string& Duration) = 0;

};


#endif //SPUTIFY_ACCOUNT_H
