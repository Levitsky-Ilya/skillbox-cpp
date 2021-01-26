#include <iostream>

int main() {
    float channels[] = {88.6, 89.6, 90.5, 91.8, 92.0, 95.1, 96.4, 102.8, 106.2, 108.0};
    int channel = 1, channelSwitch = 1;

    std::cout << "\nTurning on! Change channels by entering a channel number between 1 and 10. Enter 0 to turn off\n\n";
    while (channelSwitch != 0) {
        if (channelSwitch < 0 || channelSwitch > 10) {
            std::cout << "There is no such channel! Enter another one.\n";
        } else {
            channel = channelSwitch;
        }
        std::cout << "Now playing channel #" << channel
            << ", " << channels[channel - 1] << " FM.\n";
        std::cin >> channelSwitch;
    }
    std::cout << "Turning off. Thank you for listening!\n";
}
