
#include "Artist.h"

Artist::Artist(string &User_Name, string &Password, string &User_mode, int &Id) : Account(User_Name, Password,
                                                                                          User_mode, Id) {

}

void Artist::add_song(string &Title, string &Path, string &Year,string& Album, string &Tags, string &Duration) {
    int yearnumber = handle_year(Year);
    this->songs.push_back(new Song(Title,Path,yearnumber,Album,Tags,Duration));
    songs[songs.size() - 1]->set_artist(this->get_username());
}

int Artist::handle_year(string &Syear) {
    try {
        size_t pos;
        int result = std::stoi(Syear, &pos);
        if (pos < Syear.size()) {
            throw std::invalid_argument(BADREQUESTERROR);
        }

        return result;
    } catch (const std::invalid_argument& e) {
        throw invalid_argument(BADREQUESTERROR);
    } catch (const std::out_of_range& e) {
        throw invalid_argument(BADREQUESTERROR);
    }
}

void Artist::add_playlist(string &Name) {
    throw invalid_argument(BADREQUESTERROR);
}

void Artist::add_song_to_playlist(string &Name,Song* Song) {
    throw invalid_argument(BADREQUESTERROR);
}

void Artist::get_playlists_info() {
    throw invalid_argument(BADREQUESTERROR);

}

void Artist::get_registered_musics() {
    if (this->songs.empty()){throw invalid_argument(EMPTYERROR);}
    print_songs();
}

void Artist::print_songs() {
    cout << ONE_MUSIC_PRINT_DECP << endl;
    for (auto& music : songs) {
        cout << music->get_id() << LINE_SPACE;
        cout << music->get_title() << LINE_SPACE;
        cout << music->get_artist_name() << LINE_SPACE;
        cout << music->get_year() << LINE_SPACE;
        cout << music->get_album() << LINE_SPACE;
        cout << music->get_tags() << LINE_SPACE;
        cout << music->get_duration_str() << endl;
    }
}
