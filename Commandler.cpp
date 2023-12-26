
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

    }else if (First_word == DELETE_METHOD){

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

void Commandler::handle_post_commands(string& command,string& action) {


    if (action == SIGNUP){
        signup_command(command);
    }

    if(action == LOGIN){
        login_command(command);
    }

    if(action == LOGOUT){
        logout_command();
    }

    if (action == MUSIC_ADD){
        music_command(command);
    }

}

void Commandler::handle_get_commands(string &command, string &action) {
    if (action == GET_MUSICS){
        get_musics();
    }
    if (action == GET_USERS){
        get_users();
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
    vector<string> expectedParams = {TITLE , PATH , YEARSTR , TAGS , DURATIONSTR};

    try {
        command_parser(command,expectedParams);
        this->server->add_music(params[TITLE],params[PATH],params[YEARSTR],params[TAGS],params[DURATIONSTR]);

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



