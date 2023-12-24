
#include "Song.h"

Song::Song(string &Title, string &Path, int &Year, string &Tagstring, string &Songduration){
    this->title = Title;
    this->path = Path;
    this->year = Year;
    tag_parser(Tagstring);
    duration = new Duration(Songduration);
}

void Song::tag_parser(string& Tagstring) {
    std::istringstream iss(Tagstring);
    std::string tag;

    while (std::getline(iss, tag, ';')) {
        this->tags.push_back(tag);
    }
}
