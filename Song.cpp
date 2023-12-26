
#include "Song.h"

Song::Song(string &Title, string &Path, int &Year, string &Tagstring, string &Songduration){
    this->title = Title;
    this->path = Path;
    this->year = Year;
    tag_parser(Tagstring);
    duration = new Duration(Songduration);
    id = 0;
}

void Song::tag_parser(string& Tagstring) {
    std::istringstream iss(Tagstring);
    std::string tag;

    while (std::getline(iss, tag, TAGDELIMITER)) {
        this->tags.push_back(tag);
    }
}

void Song::set_id(int &Id) {
    this->id = Id;
}

void Song::set_artist(string Artist_Name) {
    artist_name = Artist_Name;
}

int Song::get_id() {
    return this->id;
}

string Song::get_title() {
    return this->title;
}

string Song::get_artist_name() {
    return this->artist_name;
}
