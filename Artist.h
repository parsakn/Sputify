
#ifndef SPUTIFY_ARTIST_H
#define SPUTIFY_ARTIST_H

#include "Account.h"
#include "Song.h"
#include "iostream"
#include "vector"

class Artist : public Account{
private:
    vector<Song*> songs;

public:
};


#endif //SPUTIFY_ARTIST_H
