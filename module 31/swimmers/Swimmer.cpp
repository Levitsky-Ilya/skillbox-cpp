//
// Created by leviz on 15.08.2021.
//

#include "Swimmer.h"

std::mutex coutAccess;
std::mutex finishAccess;

std::multimap<double, std::string> g_finishRecords;

#include <utility>

Swimmer::Swimmer(std::string name, double speed) :
        m_name(std::move(name)),
        m_speed(speed) {}

void Swimmer::swim() {
    double distance = 100.0;
    for (double distanceLeft = distance - m_speed; distanceLeft >= m_speed; distanceLeft -= m_speed) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        coutAccess.lock();
        std::cout << "Swimmer " << m_name << " swam " << distance - distanceLeft << " m.\n";
        coutAccess.unlock();
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    finishAccess.lock();
    g_finishRecords.insert({distance / m_speed, m_name});
    finishAccess.unlock();
    std::cout << "Swimmer " << m_name << " finished.\n";

}

void Swimmer::start() {
    m_thread = new std::thread(&Swimmer::swim, this);
}

void Swimmer::finish() {
    m_thread->join();
}
