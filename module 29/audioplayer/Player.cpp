//
// Created by leviz on 05.07.2021.
//

#include "Player.h"

void Player::shuffle() {
    if (tracks.size() > 1) {
        Track *randomTrack;
        do {
            randomTrack = &tracks[rand() % tracks.size()];
        } while (randomTrack == currentTrack);
        currentTrack = randomTrack;
    }
}

void Player::play() {

    if (state == PLAYING) {
        return;
    }

    if (tracks.empty()) {
        std::cout << "No tracks downloaded.\n";
        return;
    }

    state = PLAYING;
    std::cout << "Playing " << currentTrack->getName() << ".\n"
                 " Release Date: " << std::put_time(&currentTrack->getDateRelease(), "%F") << ".\n"
                 " Duration: " << currentTrack->getDuration() << ".\n";

}

void Player::play(const std::string& trackName) {

    // Empty track name interpreted as playing the current track
    if (trackName.empty()) {
        play();
    }

    if (state == PLAYING) {
        return;
    }

    if (tracks.empty()) {
        std::cout << "No tracks downloaded.\n";
        return;
    }

    bool trackFound = false;
    for (auto &track : tracks) {
        if (track.getName() == trackName) {
            currentTrack = &track;
            trackFound = true;
            break;
        }
    }
    if (trackFound) {
        play();
    } else {
        std::cout << "Track \"" << trackName << "\" not found.\n";
    }
}

void Player::pause() {
    if (state == PLAYING) {
        state = PAUSED;
        std::cout << "Paused\n";
    }
}

void Player::next() {
    stop();
    std::cout << "Changing track...\n";
    shuffle();
    play();
}

void Player::stop() {
    if (state != STOPPED) {
        state = STOPPED;
        std::cout << "Stopped\n";
    }
}

void Player::downloadTracks() {
    // Five tracks are prerecorded
    Track track;
    std::tm dateRelease{};

    dateRelease.tm_mday = 3; dateRelease.tm_mon = 3; dateRelease.tm_year = 50;
    track.setName("Freelance");
    track.setDateRelease(dateRelease);
    track.setDuration(300);
    tracks.push_back(track);

    dateRelease.tm_mday = 4; dateRelease.tm_mon = 4; dateRelease.tm_year = 60;
    track.setName("Unmade");
    track.setDateRelease(dateRelease);
    track.setDuration(200);
    tracks.push_back(track);

    dateRelease.tm_mday = 5; dateRelease.tm_mon = 5; dateRelease.tm_year = 70;
    track.setName("This Time Around");
    track.setDateRelease(dateRelease);
    track.setDuration(150);
    tracks.push_back(track);

    dateRelease.tm_mday = 6; dateRelease.tm_mon = 6; dateRelease.tm_year = 80;
    track.setName("Alien");
    track.setDateRelease(dateRelease);
    track.setDuration(100);
    tracks.push_back(track);

    dateRelease.tm_mday = 7; dateRelease.tm_mon = 7; dateRelease.tm_year = 90;
    track.setName("Money");
    track.setDateRelease(dateRelease);
    track.setDuration(250);
    tracks.push_back(track);

    shuffle();
}
