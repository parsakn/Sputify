
#include "SputifyCore.h"

SputifyCore::SputifyCore() {
    this->account_id_handler = new IdGenerator();
    this->songs_id_handler = new IdGenerator();
    this->logged_in_user = nullptr;
}

SputifyCore::~SputifyCore() {

}

void SputifyCore::signup(string& Username, string& Password, string& Mode) {
    if (logged_in_user != nullptr){
        throw invalid_argument(PERMISSIONDENIEDERROR);
    }
    if (find_username(Username)){
        throw invalid_argument(BADREQUESTERROR);
    }
    int Id = this->account_id_handler->assign_id();
    if (Mode == USER){
        accounts.push_back(new User(Username,Password,Mode,Id));
    } else{
        accounts.push_back(new Artist(Username,Password,Mode,Id));
    }

    this->logged_in_user = accounts[accounts.size()-1];
    cout << OKMSG << endl;
}

bool SputifyCore::find_username(string &Username) {
    bool isfound = false;
    for (int i = 0; i < this->accounts.size(); ++i) {
        if (accounts[i]->get_username() == Username){
            isfound = true;
            break;
        }
    }
    return isfound;
}

void SputifyCore::login(string &Username, string &Password) {
    if(logged_in_user == nullptr) {
        for (int i = 0; i < this->accounts.size(); ++i) {
            if (accounts[i]->get_username() == Username && accounts[i]->get_password() != Password) {
                throw invalid_argument(PERMISSIONDENIEDERROR);
            }
            if (accounts[i]->get_username() == Username && accounts[i]->get_password() == Password) {
                this->logged_in_user = accounts[i];
                cout << OKMSG << endl;
            }
        }
    }else{
        throw invalid_argument(PERMISSIONDENIEDERROR);
    }
}

void SputifyCore::logout() {
    if (this->logged_in_user != nullptr) {
        this->logged_in_user = nullptr;
        cout << OKMSG << endl;
    } else{
        throw invalid_argument(PERMISSIONDENIEDERROR);
    }

}

void SputifyCore::add_music(string &Title, string &Path, string &Year,string& Album, string &Tags, string &Duration) {
    if (this->logged_in_user != nullptr){
        this->logged_in_user->add_song(Title,Path,Year,Album,Tags,Duration);
        int Id = songs_id_handler->assign_id();
        this->logged_in_user->get_last_song()->set_id(Id);
        this->songs.push_back(logged_in_user->get_last_song());
        cout << OKMSG << endl;
    } else{
        throw invalid_argument (PERMISSIONDENIEDERROR);
    }
}

void SputifyCore::show_musics() {
    if (this->logged_in_user != nullptr){
        if (this->songs.empty()){throw invalid_argument(EMPTYERROR);}
        this->print_songs();
    }else{
        throw invalid_argument(PERMISSIONDENIEDERROR);
    }
}

void SputifyCore::print_songs() {
    cout << SONGPRINTINGDESCRIPTIONLINE << endl;
    for (int i = 0; i < songs.size(); ++i) {
        cout << songs[i]->get_id() << LINE_SPACE << songs[i]->get_title() << LINE_SPACE << songs[i]->get_artist_name() << endl;
    }
}

void SputifyCore::show_users() {
    if (this->logged_in_user != nullptr){
        this->print_users();
    }else{
        throw invalid_argument(PERMISSIONDENIEDERROR);
    }
}


void SputifyCore::print_users() {
    cout << USERPRINTINGDESCRIPTIONLINE << endl;
    for (int i = 0; i < accounts.size(); ++i) {
        cout << accounts[i]->get_id() << LINE_SPACE;
        cout << accounts[i]->get_mode() << LINE_SPACE;
        cout << accounts[i]->get_username() << LINE_SPACE;
        if (accounts[i]->get_mode() == ARTIST){ cout << accounts[i]->get_songs_count() << endl;}
        else { cout << accounts[i]->get_playlists_count() << endl;}
    }
}

void SputifyCore::show_specific_music(int Id) {
    if (logged_in_user == nullptr){throw invalid_argument(PERMISSIONDENIEDERROR);}
    Song* music_in_demand = nullptr;
    for (auto & song : songs) {
        if (song->get_id() == Id){
            music_in_demand = song;
            break;
        }
    }
    if (music_in_demand == nullptr){
        throw invalid_argument(NOTFOUNDERROR);
    } else{
        print_specific_music(music_in_demand);
    }
}

void SputifyCore::print_specific_music(Song *music) {
    cout << ONE_MUSIC_PRINT_DECP << endl;
    cout << music->get_id() << LINE_SPACE;
    cout << music->get_title() << LINE_SPACE;
    cout << music->get_artist_name() << LINE_SPACE;
    cout << music->get_year() << LINE_SPACE;
    cout << music->get_album() << LINE_SPACE;
    cout << music->get_tags() << LINE_SPACE;
    cout << music->get_duration_str() << endl;

}

void SputifyCore::show_specific_user(int Id) {
    if (logged_in_user == nullptr){throw invalid_argument(PERMISSIONDENIEDERROR);}
    Account* account_in_demand = nullptr;
    for (auto & account : accounts) {
        if (account->get_id() == Id){
            account_in_demand = account;
            break;
        }
    }
    if (account_in_demand == nullptr){
        throw invalid_argument(NOTFOUNDERROR);
    } else{
        print_specific_user(account_in_demand);
    }
}

void SputifyCore::print_specific_user(Account *account) {
    cout << "ID: " << account->get_id() << endl;
    cout << "Mode: " << account->get_mode() << endl;
    cout << "Username: " << account->get_username() << endl;
    if (account->get_mode() == ARTIST){
        cout << "Playlists: " ;
        for (int i = 0; i < account->get_playlists_count(); ++i) {

        }
    } else{

    }


}

void SputifyCore::add_playlist(string &Name) {
    if (this->logged_in_user != nullptr){
        this->logged_in_user->add_playlist(Name);
        cout << OKMSG << endl;
    } else{
        throw invalid_argument (PERMISSIONDENIEDERROR);
    }
}

void SputifyCore::add_song_to_playlist(string &Name, int Id) {
    if (this->logged_in_user != nullptr){
        Song* song_in_demand = find_song(Id);
        this->logged_in_user->add_song_to_playlist(Name,song_in_demand);
        cout << OKMSG << endl;
    } else{
        throw invalid_argument (PERMISSIONDENIEDERROR);
    }
}

void SputifyCore::get_playlist_info(int Id) {
    if(logged_in_user != nullptr){
        if(logged_in_user->get_mode() == ARTIST){throw invalid_argument(BADREQUESTERROR);}
        Account* user_in_demand = find_user(Id);
        user_in_demand->get_playlists_info();
    } else{
        throw invalid_argument(PERMISSIONDENIEDERROR);
    }
}

Song *SputifyCore::find_song(int id) {
    for (auto & song : songs) {
        if (song->get_id() == id){
            return song;
        }
    }
    throw invalid_argument(NOTFOUNDERROR);
}

Account *SputifyCore::find_user(int id) {
    for (auto & acc : accounts) {
        if (acc->get_id() == id){
            return acc;
        }
    }
    throw invalid_argument(NOTFOUNDERROR);
}

void SputifyCore::remove_music(int Id) {
    if (this->logged_in_user != nullptr){
        if(this->logged_in_user->get_mode() == USER){throw invalid_argument(BADREQUESTERROR);}
        Song* music_in_demand = find_song(Id);
        for (auto & account : accounts) {
            account->remove_song_from_playlists(music_in_demand);
        }
        songs.erase(std::remove(songs.begin(), songs.end(), music_in_demand), songs.end());
        delete music_in_demand;
        cout << OKMSG << endl;
    } else{
        throw invalid_argument (PERMISSIONDENIEDERROR);
    }

}

void SputifyCore::registered_music() {
    if (this->logged_in_user != nullptr){
        this->logged_in_user->get_registered_musics();
    } else{
        throw invalid_argument(PERMISSIONDENIEDERROR);
    }
}



