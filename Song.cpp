
#include "Song.h"

Song::Song(string &Title, string &Path, int &Year, string& Album , string &Tag_str, string &Duration_Str){
    this->title = Title;
    this->path = Path;
    this->year = Year;
    this->album = Album;
    tag_parser(Tag_str);
    duration = new Duration(Duration_Str);
    id = 0;
}

void Song::tag_parser(string& Tags_Str) {
    std::istringstream iss(Tags_Str);
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

int Song::get_year() {
    return year;
}

string Song::get_duration_str() {
    return this->duration->formatDuration();
}

string Song::get_tags() {
    std::stringstream ss;
    for (const auto& name : tags) {
        if (&name != &tags[0]) {
            ss << ";";
        }
        ss << name;
    }
    std::string result = ss.str();
    return result;
}

Duration *Song::get_duration() {
    return this->duration;
}

string Song::get_album() {
    return album;
}
