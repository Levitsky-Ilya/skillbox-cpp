//
// Created by leviz on 26.10.2021.
//

#include "fishing.h"

const char *FishException::what() const {
    return "A Fish. Congratulations!";
}

const char *BootException::what() const {
    return "A Boot... You'll get lucky next time.";
}

Pound::Pound() {
    int i = 0;
    for ( ; i < m_numFish; i++) {
        m_sectors[i] = FISH;
    }
    for ( ; i < m_numFish + m_numBoot; i++) {
        m_sectors[i] = BOOT;
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(m_sectors.begin(), m_sectors.end(), g);
}

void Pound::chooseSector(int sectorIndex) {
    /* This section is redundant. Reuse exceptions of vector.
    if (sectorIndex < 0 || sectorIndex >= m_numSectors) {
        throw std::invalid_argument ("Invalid argument sectorIndex = " + std::to_string(sectorIndex));
    }
     */

    // m_sectors.at(sectorIndex) throws std::out_of_range if sectorIndex is incorrect.
    SectorType sectorType = m_sectors.at(sectorIndex);
    if (sectorType == FISH) {
        throw FishException {};
    } else if (sectorType == BOOT) {
        throw BootException {};
    }
}
