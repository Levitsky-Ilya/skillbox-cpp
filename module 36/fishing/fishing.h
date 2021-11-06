//
// Created by leviz on 26.10.2021.
//

#ifndef FISHING_FISHING_H
#define FISHING_FISHING_H

#include <array>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <random>

class FishException : public std::exception
{
    const char * what() const override;
};

class BootException : public std::exception
{
    const char * what() const override;
};

class Pound {
public:
    Pound();

    void chooseSector(int sectorIndex);

private:
    static const int m_numSectors = 9;
    static const int m_numFish = 1;
    static const int m_numBoot = 3;
    enum SectorType {
        NONE,
        FISH,
        BOOT
    };
    std::array<SectorType, m_numSectors> m_sectors {NONE};
};

#endif //FISHING_FISHING_H
