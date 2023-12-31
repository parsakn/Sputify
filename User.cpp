
#include "User.h"

User::User(string &User_Name, string &Password, string &User_mode, int &Id) : Account(User_Name, Password, User_mode,
                                                                                      Id) {

}

void User::add_song(string &Title, string &Path, string &Year,string& Album, string &Tags, string &Duration) {
    throw invalid_argument(PERMISSIONDENIEDERROR);
}

void User::add_playlist(string &Name) {
    this->playlists.push_back(new Playlist(Name));
}

void User::add_song_to_playlist(string &Name,Song* Song) {
    Playlist* target_playlist = find_playlist(Name);
    if(target_playlist->is_song_repeated(Song)){
        throw invalid_argument(BADREQUESTERROR);
    };
    target_playlist->add_song(Song);
}

void User::get_playlists_info() {
    if (playlists.empty()){throw invalid_argument(EMPTYERROR);}
    cout << PLAYLISTS_INFO_LINE << endl;
    std::sort(playlists.begin(),playlists.end(),[](Playlist* a,Playlist* b) {
        return a->get_name() < b->get_name();
    });
    for (auto & playlist : playlists) {
        cout << playlist->get_name() << LINE_SPACE <<playlist->get_song_numbers() << LINE_SPACE << playlist->get_duration() << endl;
    }
}

void User::get_registered_musics() {
    throw invalid_argument(BADREQUESTERROR);

}

