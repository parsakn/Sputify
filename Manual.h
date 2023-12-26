
#ifndef SPUTIFY_MANUAL_H
#define SPUTIFY_MANUAL_H

#include "iostream"
#include "string"


const std::string BADREQUESTERROR = "Bad Request";
const std::string PERMISSIONDENIEDERROR = "Permission Denied";
const std::string NOTFOUNDERROR = "Not Found";
const std::string OKMSG = "OK";
const std::string EMPTYERROR = "Empty";

const std::string POST_METHOD = "POST";
const std::string GET_METHOD = "GET";
const std::string PUT_METHOD = "PUT";
const std::string DELETE_METHOD = "DELETE";


const std::string SIGNUP = "signup";
const std::string LOGIN = "login";
const std::string LOGOUT = "logout";
const std::string MUSIC_ADD = "music";
const std::string GET_MUSICS = "musics";
const std::string GET_USERS = "users";
const std::string COMMAND_IDENTIFIER = "?";
const std::string DURATIONFORMATTER = ":";
const std::string LINE_SPACE = ", ";


const std::string USERNAME = "username";
const std::string PASSWORD = "password";
const std::string MODE = "mode";
const std::string TITLE = "title";
const std::string PATH = "path";
const std::string YEARSTR = "year";
const std::string TAGS = "tags";
const std::string DURATIONSTR = "duration";

const std::string USER = "user";
const std::string ARTIST = "artist";

const char COMMANDDELIMITER = '>';
const char TAGDELIMITER = ';';
const char DURATIONDELIMITER = ':';

const int SECSOFMIN = 60;
const int SECOFHOUR = 3600;

const std::string SONGPRINTINGDESCRIPTIONLINE = "ID, Name, Artist";
const std::string USERPRINTINGDESCRIPTIONLINE = "ID, Mode, Username, Playlists_number/Songs_number"



#endif //SPUTIFY_MANUAL_H
