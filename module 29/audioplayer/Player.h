//
// Created by leviz on 05.07.2021.
//

#pragma once

#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include "Track.h"

class Player {
    std::vector<Track> tracks;
    Track *currentTrack;
    enum State {
        STOPPED,
        PAUSED,
        PLAYING
    } state = STOPPED;

    //shuffle() chooses new track randomly, except the current one.
    void shuffle();
public:

    void downloadTracks();

    // play() starts the current track
    void play();

    // play(const std::string&) starts the selected track
    void play(const std::string& trackName);

    void pause();

    // next() stops current track if was playing, selects a random track and plays it immediately
    void next();

    void stop();
};
