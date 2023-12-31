
#include "Commandler.h"

Commandler::Commandler(SputifyCore* Server) {
    this->server = Server;
}

void Commandler::run() {

    try {
        input_watcher();
    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }

}

void Commandler::input_watcher() {
    while (true){
        string line;
        getline(cin, line);

        try {
            istringstream iss(line);
            string first_word;
            string second_word;
            string third_word;
            if(!(iss >> first_word >> second_word >> third_word) || third_word != COMMAND_IDENTIFIER){
                throw invalid_argument(BADREQUESTERROR);
            }
            input_seperator(line, first_word, second_word);
        } catch(invalid_argument& e) {
            cout << e.what() << endl;
        }


    }
}

void Commandler::input_seperator(string& Line, string& First_word,string& Second_word) {



    if (First_word == GET_METHOD){
        handle_get_commands(Line,Second_word);
    }else if (First_word == POST_METHOD){
        handle_post_commands(Line,Second_word);
    }else if (First_word == PUT_METHOD){
        handle_put_commands(Line,Second_word);
    }else if (First_word == DELETE_METHOD){
        handle_delete_commands(Line,Second_word);
    } else{
        throw invalid_argument(BADREQUESTERROR);
    }


}

void Commandler::command_parser(string &command, vector<string> &expectedParams) {
    istringstream iss(command);

    string token;
    while (iss >> token) {
        if (find(expectedParams.begin(), expectedParams.end(), token) != expectedParams.end()) {
            iss >> ws;
            char c;
            iss.get(c);
            string value;
            getline(iss, value, COMMANDDELIMITER);
            params[token] = value;
        }
    }

    for (const string& param : expectedParams) {
        if (params.count(param) == 0) {
            throw invalid_argument(BADREQUESTERROR);
        }
    }
}

void Commandler::handle_delete_commands(string &command, string &action) {
    if(action == DELETE_MUSIC){
        remove_music(command);
    }
}
void Commandler::handle_post_commands(string& command,string& action) {


    if (action == SIGNUP) {
        signup_command(command);
    }

    if (action == LOGIN) {
        login_command(command);
    }

    if (action == LOGOUT) {
        logout_command();
    }

    if (action == MUSIC_ADD) {
        music_command(command);
    }

    if (action == ADD_PLAYLIST) {
        add_playlist(command);
    }
}
void Commandler::handle_get_commands(string &command, string &action) {
    if (action == GET_MUSICS){
        int command_count = command_counter(command);
        if (command_count == 3) {
            get_musics();
        }else if(command_count == 5){
            get_specific_music(command);
        } else{
            throw invalid_argument(BADREQUESTERROR);
        }
    }
    if (action == GET_USERS){
        int command_count = command_counter(command);
        if (command_count == 3) {
            get_users();
        }else if(command_count == 5){
            get_specific_user(command);
        } else{
            throw invalid_argument(BADREQUESTERROR);
        }

    }
    if(action == GET_PLAYLIST_INFO){
        get_playlist_info(command);
    }
    if(action == REGISTERED_MUSIC){
        registered_music();
    }
}
void Commandler::handle_put_commands(string &command, string &action) {
    if (action == ADD_SONG_TO_PLAYLIST){
        add_song_to_playlist(command);
    }
}
void Commandler::signup_command(string &command) {
    vector<string> expectedParams = {USERNAME, PASSWORD, MODE};
    try {
        command_parser(command, expectedParams);
        if (params[MODE] != ARTIST && params[MODE] != USER) {
            throw invalid_argument(BADREQUESTERROR);
        }
        this->server->signup(params[USERNAME], params[PASSWORD], params[MODE]);
    } catch (invalid_argument& e) {
        cout << e.what() << endl;
    }
}

void Commandler::login_command(string &command) {
    vector<string> expectedParams = {USERNAME, PASSWORD};

    try {
        command_parser(command, expectedParams);
        this->server->login(params[USERNAME], params[PASSWORD]);
    } catch (invalid_argument& e) {
        cout << e.what() << endl;
    }
}

void Commandler::logout_command() {
    try {
        this->server->logout();
    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }

}

void Commandler::music_command(string &command) {
    vector<string> expectedParams = {TITLE , ALBUM ,PATH , YEARSTR , TAGS , DURATIONSTR};

    try {
        command_parser(command,expectedParams);
        this->server->add_music(params[TITLE],params[PATH],params[YEARSTR],params[ALBUM],params[TAGS],params[DURATIONSTR]);

    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }
}

void Commandler::get_musics() {
    try {
        this->server->show_musics();
    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }
}

void Commandler::get_users() {
    try {
        this->server->show_users();
    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }
}

int Commandler::command_counter(string &command_line) {
    istringstream iss(command_line);
    int word_count = 0;
    string word;
    while(iss >> word){
        word_count++ ;
    }

    return word_count;
}

void Commandler::get_specific_music(string& command) {
    vector<string> expectedParams = {ID};

    try {
        command_parser(command,expectedParams);
        int song_id = 0;
        try {
            song_id = stoi(params[ID]);
        }catch (invalid_argument& e){
            throw invalid_argument(BADREQUESTERROR);
        }
        this->server->show_specific_music(song_id);
    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }
}

void Commandler::get_specific_user(string &command) {
    vector<string> expectedParams = {ID};

    try {
        command_parser(command,expectedParams);
        int user_id = 0;
        try {
            user_id = stoi(params[ID]);
        }catch (invalid_argument& e){
            throw invalid_argument(BADREQUESTERROR);
        }
        this->server->show_specific_user(user_id);
    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }
}

void Commandler::add_playlist(string &command) {
    vector<string> expectedParams = {NAME};

    try {
        command_parser(command,expectedParams);
        this->server->add_playlist(params[NAME]);

    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }
}

void Commandler::add_song_to_playlist(string &command) {
    vector<string> expectedParams = {NAME,ID};

    try {
        command_parser(command,expectedParams);
        int song_id = 0;
        try {
            song_id = stoi(params[ID]);
        }catch (invalid_argument& e){
            throw invalid_argument(BADREQUESTERROR);
        }
        this->server->add_song_to_playlist(params[NAME],song_id);
    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }
}

void Commandler::get_playlist_info(string &command) {
    vector<string> expectedParams = {ID};
    try {
        command_parser(command,expectedParams);
        int user_id = 0;
        try {
            user_id = stoi(params[ID]);
        }catch (invalid_argument& e){
            throw invalid_argument(BADREQUESTERROR);
        }
        this->server->get_playlist_info(user_id);
    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }
}

void Commandler::remove_music(string &command) {
    vector<string> expectedParams = {ID};

    try {
        command_parser(command,expectedParams);
        int music_id = 0;
        try {
            music_id = stoi(params[ID]);
        }catch (invalid_argument& e){
            throw invalid_argument(BADREQUESTERROR);
        }
        this->server->remove_music(music_id);
    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }

}

void Commandler::registered_music() {
    try {
        this->server->registered_music();
    }catch (invalid_argument& e){
        cout << e.what() << endl;
    }
}

