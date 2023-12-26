
#include "User.h"

User::User(string &User_Name, string &Password, string &User_mode, int &Id) : Account(User_Name, Password, User_mode,
                                                                                      Id) {

}

void User::add_song(string &Title, string &Path, string &Year, string &Tags, string &Duration) {
    throw invalid_argument(PERMISSIONDENIEDERROR);
}
