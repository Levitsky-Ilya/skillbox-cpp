//
// Created by leviz on 05.07.2021.
//

#pragma once

#include <string>

class Track {
    std::string name;

    std::tm dateRelease;

    int duration;

public:
    void setName(const std::string &name);

    void setDateRelease(const tm &dateRelease);

    void setDuration(int duration);

    const std::string &getName() const;

    const tm &getDateRelease() const;

    int getDuration() const;
};
