#ifndef SPUTIFY_ACCOUNT_H
#define SPUTIFY_ACCOUNT_H
#include "iostream"
#include "string"
#include "Manual.h"
#include "vector"
#include "Song.h"
#include "Playlist.h"
#include "algorithm"

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
    int get_id() const;
    int get_songs_count();
    int get_playlists_count();
    void remove_song_from_playlists(Song* music_in_demand);
    Playlist* find_playlist(string& Name);



    virtual void add_song(string& Title,string& Path,string& Year,string& Album,string& Tags,string& Duration) = 0;
    virtual void add_playlist(string& Name) = 0;
    virtual void add_song_to_playlist(string& Name,Song* Song) = 0;
    virtual void get_playlists_info() = 0;
    virtual void get_registered_musics() = 0;
};


#endif //SPUTIFY_ACCOUNT_H
