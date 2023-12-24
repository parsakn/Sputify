
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
            if(!(iss >> first_word >> second_word >> third_word) || third_word != "?"){
                throw invalid_argument("Bad Request");
            }
            input_seperator(line, first_word, second_word);
        } catch(invalid_argument& e) {
            cout << e.what() << endl;
        }


    }
}

void Commandler::input_seperator(string& Line, string& First_word,string& Second_word) {



    if (First_word == "GET"){

    }else if (First_word == "POST"){
        handle_post_commands(Line,Second_word);
    }else if (First_word == "PUT"){

    }else if (First_word == "DELETE"){

    } else{
        throw invalid_argument("Bad Request");
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
            getline(iss, value, '>');
            params[token] = value;
        }
    }

    for (const string& param : expectedParams) {
        if (params.count(param) == 0) {
            throw invalid_argument("Bad Request");
        }
    }
}

void Commandler::handle_post_commands(string& command,string& action) {

    string ignore;

    if (action == "signup"){
        signup_command(command);
    }

    if(action == "login"){
        login_command(command);
    }

    if(action == "logout"){
        logout_command();
    }

}

void Commandler::signup_command(string &command) {
    vector<string> expectedParams = {"username", "password", "mode"};
    try {
        command_parser(command, expectedParams);
        if (params["mode"] != "artist" && params["mode"] != "user") {
            throw invalid_argument("Bad Request");
        }
        this->server->signup(params["username"], params["password"], params["mode"]);
    } catch (invalid_argument& e) {
        cout << e.what() << endl;
    }
}

void Commandler::login_command(string &command) {
    vector<string> expectedParams = {"username", "password"};

    try {
        command_parser(command, expectedParams);
        this->server->login(params["username"], params["password"]);
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




