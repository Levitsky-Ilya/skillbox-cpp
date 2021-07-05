//
// Created by leviz on 24.06.2021.
//

#include "point.h"

bool comparePoints(Point a, Point b) {
    return (a.x == b.x && a.y == b.y);
}

std::string printPoint(Point a) {
    return "(" + std::to_string(a.x) + ";" + std::to_string(a.y) + ")";
}

Point getPoint() {
    Point a;
    std::cin >> a.x >> a.y;
    return a;
}