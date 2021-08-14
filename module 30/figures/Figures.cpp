//
// Created by leviz on 12.08.2021.
//

#include "Figures.h"

// TODO check for non-positive numbers!!
/// Figure ///

Figure::Figure(Color color, Point center) :
    m_color(color),
    m_center(std::move(center)) {}

void Figure::setColor(Color color) {
    m_color = color;
}

void Figure::setCenter(Point center) {
    m_center = center;
}

Color Figure::getColor() const {
    return m_color;
}

Point Figure::getCenter() const {
    return m_center;
}

/// Circle ///

Circle::Circle(double radius, Color color, Point center) :
    Figure(color, center),
    m_radius(radius) {}

void Circle::setRadius(double radius) {
    assert(radius > 0);
    m_radius = radius;
}

double Circle::getRadius() const {
    return m_radius;
}

double Circle::getArea() const {
    return M_PI * m_radius * m_radius;
}

BoundingBox Circle::getBoundingBox() const {
    return {{m_center.first - m_radius,
             m_center.second - m_radius},
            {m_center.first + m_radius,
             m_center.second + m_radius}};
}

/// Square ///

Square::Square(double side, Color color, Point center) :
    Figure(color, center),
    m_side(side) {}

void Square::setSide(double side) {
    assert(side > 0);
    m_side = side;
}

double Square::getSide() const {
    return m_side;
}

double Square::getArea() const {
    return m_side * m_side;
}

BoundingBox Square::getBoundingBox() const {
    return {{m_center.first - m_side / 2,
             m_center.second - m_side / 2},
            {m_center.first + m_side / 2,
             m_center.second + m_side / 2}};
}

/// Triangle ///
Triangle::Triangle(double side, Color color, Point center) :
        Figure(color, center),
        m_side(side) {}

void Triangle::setSide(double side) {
    assert(side > 0);
    m_side = side;
}

double Triangle::getSide() const {
    return m_side;
}

double Triangle::getArea() const {
    return std::sqrt(3.0) * m_side * m_side / 4;;
}

BoundingBox Triangle::getBoundingBox() const {
    return {{m_center.first - m_side / 2,
             m_center.second - m_side * std::sqrt(3.0) / 6},
            {m_center.first + m_side / 2,
             m_center.second - m_side * std::sqrt(3.0) / 3}};
}

/// Rectangle ///


Rectangle::Rectangle(double height, double width, Color color, Point center) :
        Figure(color, center),
        m_height(height),
        m_width(width) {}

void Rectangle::setHeight(double height) {
    assert(height > 0);
    m_height = height;
}

void Rectangle::setWidth(double width) {
    assert(width > 0);
    m_width = width;
}

double Rectangle::getHeight() const {
    return m_height;
}

double Rectangle::getWidth() const {
    return m_width;
}

double Rectangle::getArea() const {
    return m_height * m_width;
}

BoundingBox Rectangle::getBoundingBox() const {
    return {{m_center.first - m_width / 2,
             m_center.second - m_height / 2},
            {m_center.first + m_width / 2,
             m_center.second + m_height / 2}};
}

