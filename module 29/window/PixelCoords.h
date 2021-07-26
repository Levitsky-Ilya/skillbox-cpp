//
// Created by leviz on 26.07.2021.
//

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Screen.h"

using Coords = std::pair<int, int>;

class PixelCoords {
public:
    Coords getPixelCoords();
    void setPixelCoords(Coords coords);
    std::string printPixelCoords() const;

private:
    static bool checkPixelCoords(Coords coords);

    std::pair<int, int> m_coords = {0, 0};
};

