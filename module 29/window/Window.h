//
// Created by leviz on 26.07.2021.
//

#pragma once

#include "PixelCoords.h"

class Window {
public:
    void move(PixelCoords cornerCoords);

    void resize(int width, int height);

    void display();
private:

    static bool checkWindow(PixelCoords cornerCoords, int width, int height);

    PixelCoords m_cornerCoords;
    int m_width = screen::screenWidth;
    int m_height = screen::screenHeight;
};

