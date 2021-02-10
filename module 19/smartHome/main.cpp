#include <iostream>
#include <sstream>

int simulationDuration = 48; // hours

enum switchBox {
    POWER_ALL = 1,
    POWER_SOCKETS = 2,
    LIGHTS = 4,
    LIGHTS_GARDEN = 8,
    HEATING = 16,
    PIPE_HEATING = 32,
    CONDITIONER = 64
};

// returns true if the user entered valid values for
// movementOutsideString and lightOnString variables.
// If result is false, print an error message to cerr.
bool checkInput(std::string movementOutsideString, std::string lightOnString) {
    bool result =  ((movementOutsideString == "yes" || movementOutsideString == "no") &&
            (lightOnString == "on" || lightOnString == "off"));
    if (!result)
        std::cerr << "Incorrect input. Try again.\n";
    return result;
}

// switchPower switches entry in switchBoxState to the opposite and prints out the action.
int switchPower(int switchBoxState, int entry) {
    std::string entryNames[] = {"All power",
                                "Power sockets",
                                 "Lights",
                                 "Garden lights",
                                 "Heating",
                                 "Pipe heating",
                                 "Conditioning"};
    switchBoxState ^= entry;
    int entryIndex = -1;
    while (!(entry & (1 << (++entryIndex))));
    std::cout << "[Home]: " << entryNames[entryIndex] << " turned "
              << ((switchBoxState & entry) ? "on.\n" : "off.\n");
    return switchBoxState;
}

int main() {
    // Input: 20 10 1 1
    // Input format: (int) (int) (int (0-1)) (int (0-1))
    // Input interpretation: temperature outside, temperature outside, movement outside, light is on

    std::cout << "\n***** Welcome to the SmartHome! *****\n";
    std::cout << "\n[Home]: Please, input temperature outside, "
                 "temperature outside, movement outside, light is on in format:\n"
                 "  \"<t1> <t2> <yes/no> <on/off>\"\n"
                 "where and t1 t2 are integers.\n"
                 "Thank you!\n\n";


    std::string inputString;
    int switchBoxState = POWER_ALL & POWER_SOCKETS;
    int lightsTemperature = 5000; //K
    for (int hourSim = 0; hourSim < simulationDuration; hourSim++) {
        int hour = hourSim % 24;

        float temperatureOutside, temperatureInside;
        std::string movementOutsideString;
        std::string lightOnString;
        do {
            std::cout << "[USER] (" << hour << ":00): ";
            getline(std::cin, inputString);
            std::stringstream inputStream(inputString);
            inputStream >> temperatureOutside >> temperatureInside >> movementOutsideString >> lightOnString;
        } while (!checkInput(movementOutsideString, lightOnString));

        bool movementOutside = (movementOutsideString != "no");
        bool lightOn = (lightOnString != "off");

        if (switchBoxState & POWER_ALL) {
            // *** PIPE_HEATING ***
            // Turn on pipe heating if temperature outside is lower than 0
            if (temperatureOutside < 0 && (~switchBoxState & PIPE_HEATING))
                switchBoxState = switchPower(switchBoxState, PIPE_HEATING);

            // Turn off pipe heating if temperature outside is higher than 5
            if (temperatureOutside > 5 && (switchBoxState & PIPE_HEATING))
                switchBoxState = switchPower(switchBoxState, PIPE_HEATING);

            // *** LIGHTS_GARDEN ***
            // Turn on garden lighting if movement outside and time 16:00 - 5:00
            bool lightsGardenCondition = (hour < 5 || hour > 16) && movementOutside;
            if (lightsGardenCondition && (~switchBoxState & LIGHTS_GARDEN))
                switchBoxState = switchPower(switchBoxState, LIGHTS_GARDEN);

            // Turn off otherwise
            if (!lightsGardenCondition && (switchBoxState & LIGHTS_GARDEN))
                switchBoxState = switchPower(switchBoxState, LIGHTS_GARDEN);

            // *** HEATING ***
            // Turn on heating if temperature inside lower than 22
            if (temperatureInside < 22 && (~switchBoxState & HEATING))
                switchBoxState = switchPower(switchBoxState, HEATING);

            // Turn off heating if temperature inside not lower than 25
            if (temperatureInside >= 25 && (switchBoxState & HEATING))
                switchBoxState = switchPower(switchBoxState, HEATING);

            // *** CONDITIONER ***
            // Turn on conditioning if temperature inside not lower than 30
            if (temperatureInside >= 30 && (~switchBoxState & CONDITIONER))
                switchBoxState = switchPower(switchBoxState, CONDITIONER);

            // Turn off conditioning if temperature inside not higher than 25
            if (temperatureInside <= 25 && (switchBoxState & CONDITIONER))
                switchBoxState = switchPower(switchBoxState, CONDITIONER);

            // *** LIGHTS ***
            // Turn on lights if requested by user
            if (lightOn && (~switchBoxState & LIGHTS))
                switchBoxState = switchPower(switchBoxState, LIGHTS);

            // Turn off lights if requested by user
            if (!lightOn && (switchBoxState & LIGHTS))
                switchBoxState = switchPower(switchBoxState, LIGHTS);

            if (switchBoxState & LIGHTS) {
                // lights temperature falls linearly from 5000 to 2700 between 16:00 and 20:00
                lightsTemperature = std::max(2700, std::min(5000, -hour * 575 + 11900));
                std::cout << "[Home]: Lights temperature is " << lightsTemperature << "K.\n";
            }
        }
    }

    std::cout << "\n[Home]: Simulation expired. Thank you!";
}
