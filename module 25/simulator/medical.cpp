//
// Created by leviz on 24.06.2021.
//

#include "medical.h"

Cut scalpel() {
    Cut cut;
    std::cout << "Enter point coordinates for cut begin: ";
    cut.begin = getPoint();
    std::cout << "Enter point coordinates for cut end: ";
    cut.end = getPoint();
    std::cout << "Successfully applied scalpel at "
              << printPoint(cut.begin) << "->" << printPoint(cut.end) << "\n";
    return cut;
}

bool compareCuts(Cut first, Cut last) {
    return (comparePoints(first.begin, last.begin) && comparePoints(first.end, last.end)) ||
           (comparePoints(first.begin, last.end) && comparePoints(first.begin, last.end));
}

void hemostat() {
    std::cout << "Enter point coordinates to apply hemostat: ";
    Point a = getPoint();
    std::cout << "Successfully applied hemostat at " << printPoint(a) << "\n";
}

void tweezers() {
    std::cout << "Enter point coordinates to apply tweezers: ";
    Point a = getPoint();
    std::cout << "Successfully applied tweezers at " << printPoint(a) << "\n";
}

// suture takes 2 points: begin and end of a cut, done earlier with scalpel.
void suture(Cut origCut) {
    Cut cut = {0, 0};
    while (!compareCuts(cut, origCut)) {
        std::cout << "Enter point coordinates for cut begin: ";
        cut.begin = getPoint();
        std::cout << "Enter point coordinates for cut end: ";
        cut.end = getPoint();
        if (!compareCuts(cut, origCut)) {
            std::cout << "Applied suture at wrong points! Try again!\n";
        }
    }
    std::cout << "Successfully applied suture at "
              << printPoint(cut.begin) << "->" << printPoint(cut.end) << "\n";
}

void operation() {
    std::cout << "Operation begins\n";
    std::string command;
    do {
        std::cout << "Enter command \"scalpel\" to start.\n";
        std::cin >> command;
    } while (command != "scalpel");
    Cut cut = scalpel();

    while (command != "suture") {
        std::cout << "Enter command \"hemostat\" to apply hemostat.\n"
                     "Enter command \"tweezers\" to apply tweezers.\n"
                     "Enter command \"suture\" to finish operation\n.";
        std::cin >> command;
        if (command == "hemostat") {
            hemostat();
        } else if (command == "tweezers") {
            tweezers();
        } else if (command == "suture") {
            suture(cut);
        } else {
            std::cout << "Unknown command!\n";
        }
    }

    std::cout << "Operation is finished.\n";
}