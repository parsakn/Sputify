
#include "Playlist.h"

Playlist::Playlist(string &Name) {
    this->name = Name;
}

void Playlist::add_song(Song *song) {
    playlist_songs.push_back(song);
}

string Playlist::get_name() {
    return this->name;
}

string Playlist::get_duration() {
    int seconds_sum = 0;
    int hours = 0 ;
    int minutes = 0;
    for (auto & playlist_song : playlist_songs) {
        seconds_sum = seconds_sum + playlist_song->get_duration()->get_in_seconds();
    }
    int seconds = seconds_sum;
    convert_seconds(hours,minutes,seconds);
    Duration playlist_dur(hours,minutes,seconds);
    return playlist_dur.formatDuration();
}

void Playlist::convert_seconds(int &Hours, int &Minutes, int &Seconds) {
    while(Seconds >= 60){
        Minutes++;
        Seconds = Seconds - 60;
        if (Minutes == 60){
            Minutes = 0;
            Hours++;
        }
    }
}

int Playlist::get_song_numbers() {
    return playlist_songs.size();
}

bool Playlist::is_song_repeated(Song *Song) {
    for (int i = 0; i < playlist_songs.size(); ++i) {
        if (playlist_songs[i] == Song){
            return true;
        }
    }
    return false;
}

void Playlist::remove_song(Song *muisc_in_demand) {
    auto it = std::find(playlist_songs.begin(), playlist_songs.end(), muisc_in_demand);
    if (it != playlist_songs.end()) {
        playlist_songs.erase(it);
    }
}
