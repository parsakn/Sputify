
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

void SputifyCore::add_music(string &Title, string &Path, string &Year, string &Tags, string &Duration) {
    if (this->logged_in_user != nullptr){
        this->logged_in_user->add_song(Title,Path,Year,Tags,Duration);
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

