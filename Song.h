
#ifndef SPUTIFY_SONG_H
#define SPUTIFY_SONG_H

#include "iostream"
#include "string"
#include "vector"
#include "Duration.h"
#include "sstream"
#include "Manual.h"

using namespace std;

class Song {
private:

    string title;
    string path;
    int year;
    vector<string> tags;
    Duration* duration;
    void tag_parser(string& Tagstring);
    int id;
    string artist_name;


public:
    Song(string &Title, string &Path, int &Year, string &Tagstring, string &Songduration);
    void set_id(int& Id);
    void set_artist(string Artist_Name);

    int get_id();
    string get_title();
    string get_artist_name();
};


#endif //SPUTIFY_SONG_H
