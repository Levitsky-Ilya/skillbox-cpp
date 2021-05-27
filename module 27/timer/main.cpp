#include <iostream>
#include <ctime>
#include <iomanip>
#include <thread>
#include <chrono>

#define SEC_IN_MIN (60)

int main() {
    std::tm tm_timeToWait {};
    std::tm *p_tm_timeToWait = &tm_timeToWait;

    std::cout << "Input time to wait for (MM:SS):\n" << std::endl;
    // No input check here! Input is assumed to be correct!
    std::cin >> std::get_time(p_tm_timeToWait, "%M:%S");

    auto secondsToWait = (std::time_t)(p_tm_timeToWait->tm_min * SEC_IN_MIN + p_tm_timeToWait->tm_sec);
    for (; secondsToWait > 0; secondsToWait--) {
        p_tm_timeToWait = std::localtime(&secondsToWait);
        std::cout << std::put_time(p_tm_timeToWait, "%M:%S") << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    std::cout << "DING! DING! DING! \n";
    return 0;
}
