//
// Created by leviz on 24.06.2021.
//

#pragma once

#include <string>
#include <iostream>

struct Point {
    double x;
    double y;
};

bool comparePoints(Point a, Point b);

std::string printPoint(Point a);

Point getPoint();
