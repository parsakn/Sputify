#ifndef SPUTIFY_PLAYLIST_H
#define SPUTIFY_PLAYLIST_H

#include "iostream"
#include "string"
#include "vector"
#include "Duration.h"
#include "Song.h"

using namespace std;

class Playlist {
private:
    string name;
    vector <Song*> playlist_songs;
    void convert_seconds(int& Hours,int& Minutes,int& Seconds);
public:
    explicit Playlist(string& Name);
    void add_song(Song* song);
    string get_duration();
    string get_name();
    int get_song_numbers();
    bool is_song_repeated(Song* Song);
    void remove_song(Song* muisc_in_demand);
};


#endif //SPUTIFY_PLAYLIST_H
