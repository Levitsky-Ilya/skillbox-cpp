//
// Created by leviz on 05.07.2021.
//

#include "Track.h"

void Track::setName(const std::string &name) {
    Track::name = name;
}

void Track::setDateRelease(const tm &dateRelease) {
    Track::dateRelease = dateRelease;
}

void Track::setDuration(int duration) {
    Track::duration = duration;
}

const std::string &Track::getName() const {
    return name;
}

const tm &Track::getDateRelease() const {
    return dateRelease;
}

int Track::getDuration() const {
    return duration;
}
