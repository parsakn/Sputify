
#ifndef SPUTIFY_COMMANDLER_H
#define SPUTIFY_COMMANDLER_H

#include "Manual.h"
#include "Account.h"
#include "SputifyCore.h"
#include "sstream"
#include "unordered_map"

class Commandler {
private:
    SputifyCore* server;
    unordered_map<string, string> params;


    void input_watcher();
    void input_seperator(string& Line,string& First_word,string& Second_word);
    void handle_get_commands(string& command,string& action);
    void handle_put_commands(string& command,string& action);
    void handle_post_commands(string& command,string& action);
    void handle_delete_commands(string& command,string& action);
    void command_parser(string& command, vector<string>& expectedParams);

    void signup_command(string& command);
    void login_command(string& command);
    void music_command(string& command);
    void logout_command();
public:
    Commandler(SputifyCore* Server);
    void run();
};


#endif //SPUTIFY_COMMANDLER_H
