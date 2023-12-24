
#ifndef SPUTIFY_SONG_H
#define SPUTIFY_SONG_H

#include "iostream"
#include "string"
#include "vector"
#include "Duration.h"
#include "sstream"

using namespace std;

class Song {
private:

    string title;
    string path;
    int year;
    vector<string> tags;
    Duration* duration;
    void tag_parser(string& Tagstring);


public:
    Song(string &Title, string &Path, int &Year, string &Tagstring, string &Songduration);
};


#endif //SPUTIFY_SONG_H
