//
// Created by leviz on 24.06.2021.
//

#pragma once

#include "point.h"

struct Cut {
    Point begin;
    Point end;
};

bool compareCuts(Cut first, Cut last);

// scalpel takes 2 points: begin and end of a cut. outputs a cut. Enters message in console.
Cut scalpel();

// hemostat takes 1 point: coordinates of hemostat. Enters message in console.
void hemostat();

// tweezers takes 1 point: coordinates of tweezers. Enters message in console.
void tweezers();

// suture takes 2 points: begin and end of a cut, done earlier with scalpel.
void suture();

// operation starts with scalpel() call, zero or more hemostat() or tweezers() calls, finishes with suture() call.
// Cuts for scalpel() and suture() shall be identical.
void operation();