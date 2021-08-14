//
// Created by leviz on 12.08.2021.
//

#ifndef FIGURES_FIGURES_H
#define FIGURES_FIGURES_H

#define _USE_MATH_DEFINES

#include <cassert>
#include <utility>
#include <cmath>

enum Color {
    NONE = 0,
    RED,
    GREEN,
    BLUE
};

using Point = std::pair<double, double>;

using BoundingBox = std::pair<Point, Point>;

class Figure {
public:

    explicit Figure(Color color = NONE, Point center = {0, 0});

    void setColor (Color color);

    void setCenter (Point center);

    Color getColor () const;

    Point getCenter() const;

    Color m_color;
    Point m_center;
};

class Circle : public Figure {
public:

    Circle(double radius, Color color = NONE, Point center = {0, 0});

    void setRadius(double radius);

    double getRadius() const;

    double getArea() const;

    BoundingBox getBoundingBox() const;

    double m_radius;
};

class Square : public Figure {
public:

    explicit Square(double side, Color color = NONE, Point center = {0, 0});

    void setSide(double side);

    double getSide() const;

    double getArea() const;

    BoundingBox getBoundingBox() const;

    double m_side;
};

class Triangle : public Figure {
public:

    explicit Triangle(double side, Color color = NONE, Point center = {0, 0});

    void setSide(double side);

    double getSide() const;

    double getArea() const;

    BoundingBox getBoundingBox() const;

    double m_side;
};

class Rectangle : public Figure {
public:

    Rectangle(double height, double width, Color color = NONE, Point center = {0, 0});

    void setHeight(double height);

    void setWidth(double width);

    double getHeight() const;

    double getWidth() const;

    double getArea() const;

    BoundingBox getBoundingBox() const;

    double m_height;
    double m_width;
};

#endif //FIGURES_FIGURES_H
