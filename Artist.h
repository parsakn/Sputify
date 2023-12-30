
#ifndef SPUTIFY_ARTIST_H
#define SPUTIFY_ARTIST_H

#include "Account.h"
#include "Song.h"
#include "iostream"
#include "vector"
#include "Manual.h"

class Artist : public Account{
private:


    int handle_year(string& Syear);

public:
    Artist(string& User_Name, string& Password, string& User_mode,int& Id);
    ~Artist() = default;

    virtual void add_song(string& Title,string& Path,string& Year,string& Tags,string& Duration) override;
    virtual void add_playlist(string& Name) override ;
    virtual void add_song_to_playlist(string& Name,Song* Song) override;
    virtual void get_playlists_info() override;

};


#endif //SPUTIFY_ARTIST_H
