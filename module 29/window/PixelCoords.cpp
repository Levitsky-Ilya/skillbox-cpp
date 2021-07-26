//
// Created by leviz on 26.07.2021.
//

#include "PixelCoords.h"

Coords PixelCoords::getPixelCoords() {
    return m_coords;
}

void PixelCoords::setPixelCoords(Coords coords) {
    std::cout << "DEBUG: " << coords.first << " " << coords.second << "\n";
    if (!checkPixelCoords(coords)) {
        std::cout << "Pixel coordinates are invalid\n";
    } else {
        m_coords = coords;
    }
}

std::string PixelCoords::printPixelCoords() const {
    return "(" + std::to_string(m_coords.first) + ", " + std::to_string(m_coords.second) + ")";
}

bool PixelCoords::checkPixelCoords(Coords coords) {
    return (coords.first >= 0 && coords.first < screen::screenWidth &&
        coords.second > 0 && coords.second < screen::screenHeight);
}
