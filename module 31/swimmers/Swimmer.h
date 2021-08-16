//
// Created by leviz on 15.08.2021.
//

#ifndef SWIMMERS_SWIMMER_H
#define SWIMMERS_SWIMMER_H

#include <iostream>
#include <map>
#include <mutex>
#include <thread>
#include <vector>

// TODO Do we need coutAccess?
extern std::mutex coutAccess;
extern std::mutex finishAccess;

extern std::multimap<double, std::string> g_finishRecords;

class Swimmer {
public:
    Swimmer(std::string name, double speed);

    void start();

    void finish();

private:

    void swim();

    std::string m_name;
    double m_speed;
    std::thread* m_thread;
};


#endif //SWIMMERS_SWIMMER_H
