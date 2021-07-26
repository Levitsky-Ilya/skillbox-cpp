//
// Created by leviz on 26.07.2021.
//

#include "Window.h"

void Window::move(PixelCoords cornerCoords) {
    if (!checkWindow(cornerCoords, m_width, m_height)) {
        std::cout << "Cannot move window to these coordinates.\n";
    } else {
        m_cornerCoords = cornerCoords;
        std::cout << "Moved window to " << m_cornerCoords.printPixelCoords() << ".\n";
    }
}

void Window::resize(int width, int height) {
    if (!checkWindow(m_cornerCoords, width, height)) {
        std::cout << "Cannot change window's size.\n";
    } else {
        m_width = width;
        m_height = height;
        std::cout << "Changed window's size to " << m_width << "x" << m_height << ".\n";
    }
}

void Window::display() {
    int row = 0;
    int x = m_cornerCoords.getPixelCoords().first;
    int y = m_cornerCoords.getPixelCoords().second;

    std::cout << "\n";

    for (; row < y; row++) {
        std::cout << std::string(screen::screenWidth, '0') << "\n";
    }

    for (; row < y + m_height; row++) {
        std::cout <<
            std::string(x, '0') <<
            std::string(m_width, '1') <<
            std::string(screen::screenWidth - x - m_width, '0') <<
            "\n";
    }

    for (; row < screen::screenHeight; row++) {
        std::cout << std::string(screen::screenWidth, '0') << "\n";
    }

    std::cout << "\n";
}

bool Window::checkWindow(PixelCoords cornerCoords, int width, int height) {
    return (width > 0 &&
            height > 0 &&
            cornerCoords.getPixelCoords().first + width <= screen::screenWidth &&
            cornerCoords.getPixelCoords().second + height <= screen::screenHeight);
}
