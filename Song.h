
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
    string album;
    int year;
    vector<string> tags;
    Duration* duration;
    void tag_parser(string& Tags_Str);
    int id;
    string artist_name;


public:
    Song(string &Title, string &Path, int &Year, string& Album, string &Tag_str, string &Duration_Str);
    void set_id(int& Id);
    void set_artist(string Artist_Name);

    int get_id();
    int get_year();
    string get_title();
    string get_album();
    string get_duration_str();
    Duration* get_duration();
    string get_tags();
    string get_artist_name();
};


#endif //SPUTIFY_SONG_H
