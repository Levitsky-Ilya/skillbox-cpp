//
// Created by leviz on 30.06.2021.
//

#pragma once

#include <array>

using Ram = std::array<int, 8>;

extern Ram ram;

void read(Ram in);

Ram write();
