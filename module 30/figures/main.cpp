#include <iostream>
#include <sstream>
#include "Figures.h"

Color stringToColor(const std::string& colorStr) {
    return (colorStr == "red") ? RED :
           (colorStr == "green") ? GREEN :
           (colorStr == "blue") ? BLUE : NONE;
}

/* TODO question - can I have only one function handleInit(Figure& figure, std::stringstream& commandStream)
 * that Automatically knows from figure if this is in fact a child class (e.g. Circle)?
 * This would reduce the code substantially.
*/

// handleCircleInit initializes circle from arguments in commandStream.
// Prints if errors have occurred.
// Assumes that number inputs are valid real numbers.
// Returns true if finished successfully.
bool handleCircleInit(Circle& circle, std::stringstream& commandStream) {
    double radius;
    Color color = NONE;
    Point center;
    std::string argument;

    // Parse radius
    if (commandStream.eof()) {
        std::cout << "Command circle requires at least 1 argument\n";
        return false;
    }
    commandStream >> radius;
    if (radius <= 0) {
        std::cout << "Radius is invalid.\n";
        return false;
    }

    // Parse color
    if (!commandStream.eof()) {
        commandStream >> argument;
        color = stringToColor(argument);
    }

    // Parse center
    if (!commandStream.eof()) {
        commandStream >> center.first;
    }
    if (!commandStream.eof()) {
        commandStream >> center.second;
    }

    circle.setRadius(radius);
    circle.setColor(color);
    circle.setCenter(center);
    return true;
}

// handleSquareInit initializes square from arguments in commandStream.
// Prints if errors have occurred.
// Assumes that number inputs are valid real numbers.
// Returns true if finished successfully.
bool handleSquareInit(Square& square, std::stringstream& commandStream) {
    double side;
    Color color = NONE;
    Point center;
    std::string argument;

    // Parse side
    if (commandStream.eof()) {
        std::cout << "Command square requires at least 1 argument\n";
        return false;
    }
    commandStream >> side;
    if (side <= 0) {
        std::cout << "Side is invalid.\n";
        return false;
    }

    // Parse color
    if (!commandStream.eof()) {
        commandStream >> argument;
        color = stringToColor(argument);
    }

    // Parse center
    if (!commandStream.eof()) {
        commandStream >> center.first;
    }
    if (!commandStream.eof()) {
        commandStream >> center.second;
    }

    square.setSide(side);
    square.setColor(color);
    square.setCenter(center);
    return true;
}

// handleTriangleInit initializes triangle from arguments in commandStream.
// Prints if errors have occurred.
// Assumes that number inputs are valid real numbers.
// Returns true if finished successfully.
bool handleTriangleInit(Triangle& triangle, std::stringstream& commandStream) {
    double side;
    Color color = NONE;
    Point center;
    std::string argument;

    // Parse side
    if (commandStream.eof()) {
        std::cout << "Command triangle requires at least 1 argument\n";
        return false;
    }
    commandStream >> side;
    if (side <= 0) {
        std::cout << "Side is invalid.\n";
        return false;
    }

    // Parse color
    if (!commandStream.eof()) {
        commandStream >> argument;
        color = stringToColor(argument);
    }

    // Parse center
    if (!commandStream.eof()) {
        commandStream >> center.first;
    }
    if (!commandStream.eof()) {
        commandStream >> center.second;
    }

    triangle.setSide(side);
    triangle.setColor(color);
    triangle.setCenter(center);
    return true;
}

// handleRectangleInit initializes rectangle from arguments in commandStream.
// Prints if errors have occurred.
// Assumes that number inputs are valid real numbers.
// Returns true if finished successfully.
bool handleRectangleInit(Rectangle& rectangle, std::stringstream& commandStream) {
    double height, width;
    Color color = NONE;
    Point center;
    std::string argument;

    // Parse height
    if (commandStream.eof()) {
        std::cout << "Command rectangle requires at least 2 arguments\n";
        return false;
    }
    commandStream >> height;
    if (height <= 0) {
        std::cout << "Height is invalid.\n";
        return false;
    }

    // Parse width
    if (commandStream.eof()) {
        std::cout << "Command rectangle requires at least 2 arguments\n";
        return false;
    }
    commandStream >> width;
    if (width <= 0) {
        std::cout << "Width is invalid.\n";
        return false;
    }

    // Parse color
    if (!commandStream.eof()) {
        commandStream >> argument;
        color = stringToColor(argument);
    }

    // Parse center
    if (!commandStream.eof()) {
        commandStream >> center.first;
    }
    if (!commandStream.eof()) {
        commandStream >> center.second;
    }

    rectangle.setHeight(height);
    rectangle.setWidth(width);
    rectangle.setColor(color);
    rectangle.setCenter(center);
    return true;
}


std::string getColorText(const Color& color) {
    return (color == RED) ? "red " :
           (color == GREEN) ? "green " :
           (color == BLUE) ? "blue " : "";
}

std::string getBoundingBoxText(const BoundingBox& boundingBox) {
    std::stringstream stream;
    stream << "(" << boundingBox.first.first << ";" << boundingBox.first.second  << "), "
               << "(" << boundingBox.second.first << ";" << boundingBox.second.second << ")";
    return stream.str();
}

void printAreaAndBoundingBox(const Circle& circle) {
    std::string colorStr = getColorText(circle.getColor());
    BoundingBox boundingBox = circle.getBoundingBox();

    std::cout << "The " << colorStr << "circle has area " << circle.getArea() << ".\n";
    std::cout << "The bounding box of the " << colorStr << "circle has corners "
              << getBoundingBoxText(boundingBox) << ".\n";
}

void printAreaAndBoundingBox(const Square& square) {
    std::string colorStr = getColorText(square.getColor());
    BoundingBox boundingBox = square.getBoundingBox();

    std::cout << "The " << colorStr << "square has area " << square.getArea() << ".\n";
    std::cout << "The bounding box of the " << colorStr << "square has corners "
              << getBoundingBoxText(boundingBox) << ".\n";
}

void printAreaAndBoundingBox(const Triangle& triangle) {
    std::string colorStr = getColorText(triangle.getColor());
    BoundingBox boundingBox = triangle.getBoundingBox();

    std::cout << "The " << colorStr << "triangle has area " << triangle.getArea() << ".\n";
    std::cout << "The bounding box of the " << colorStr << "triangle has corners "
              << getBoundingBoxText(boundingBox) << ".\n";
}

void printAreaAndBoundingBox(const Rectangle& rectangle) {
    std::string colorStr = getColorText(rectangle.getColor());
    BoundingBox boundingBox = rectangle.getBoundingBox();

    std::cout << "The " << colorStr << "rectangle has area " << rectangle.getArea() << ".\n";
    std::cout << "The bounding box of the " << colorStr << "rectangle has corners "
              << getBoundingBoxText(boundingBox) << ".\n";
}


int main() {
    std::cout << "Welcome to Geometrica!" << std::endl;

    std::cout << "Type following commands:\n"
                 " circle <radius> [color] [center_x] [center_y]\n"
                 " square <side> [color] [center_x] [center_y]\n"
                 " triangle <side> [color] [center_x] [center_y]\n"
                 " rectangle <height> <width> [color] [center_x] [center_y]\n"
                 " exit\n"
                 "[color] can be red, green, blue.\n";

    std::string command, argument;
    std::stringstream commandStream;

    while (command != "exit") {
        std::getline(std::cin, command);
        commandStream << command;
        commandStream >> command;

        if (command == "circle") {
            Circle circle(0);
            if (handleCircleInit(circle, commandStream)) {
                printAreaAndBoundingBox(circle);
            }
        } else if (command == "square") {
            Square square(0);
            if (handleSquareInit(square, commandStream)) {
                printAreaAndBoundingBox(square);
            }
        } else if (command == "triangle") {
            Triangle triangle(0);
            if (handleTriangleInit(triangle, commandStream)) {
                printAreaAndBoundingBox(triangle);
            }
        } else if (command == "rectangle") {
            Rectangle rectangle(0, 0);
            if (handleRectangleInit(rectangle, commandStream)) {
                printAreaAndBoundingBox(rectangle);
            }
        } else if (command != "exit") {
            std::cout << "Unknown command\n";
        }

        commandStream.str("");
        commandStream.clear();
    }

    std::cout << "Geometrica finishes.\n";
    return 0;
}
