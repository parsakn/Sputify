
#include "Playlist.h"

Playlist::Playlist(string &Name) {
    this->name = Name;
    this->playlist_duration = new Duration("00:00:00");
}
