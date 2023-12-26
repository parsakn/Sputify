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
    Duration* playlist_duration;
public:
    explicit Playlist(string& Name);
};


#endif //SPUTIFY_PLAYLIST_H
