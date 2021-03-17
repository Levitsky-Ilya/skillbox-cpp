#include <iostream>
#include <string>
#include <vector>

enum RoomType {
    BEDROOM,
    KITCHEN,
    BATHROOM,
    PLAYING_ROOM,
    LIVING_ROOM,
    UNDEFINED
};

// ***** STRUCTS ***** //

struct Room {
    RoomType type = UNDEFINED;
    float area = 0;
};

struct Stage {
    std::vector<Room> rooms = {};
    float height = 0;
};

struct House {
    float area = 0;
    std::vector<Stage> stages = {};
    bool hasFireplace = false;
};

struct Garage {
    float area = 0;
};

struct Shed {
    float area = 0;
};

struct Bathhouse {
    float area = 0;
    bool hasFireplace = false;
};

struct Homestead {
    std::vector<House> houses = {};
    std::vector<Garage> garages = {};
    std::vector<Shed> sheds = {};
    std::vector<Bathhouse> bathhouses = {};
};

struct Village {
    float area;
    std::vector<Homestead> homesteads = {};
};

// ***** FUNCTIONS ***** //

float enterFloatPos(const std::string& name) {
    std::cout << "Enter " << name << std::endl;
    std::string numberStr;
    float number;
    std::getline(std::cin, numberStr);
    number = atof(numberStr.c_str());
    while (number <= 0) {
        std::cout << "Enter a valid positive number\n";
        std::getline(std::cin, numberStr);
        number = atof(numberStr.c_str());
    }
    return number;
}

int enterInt(const std::string& name, bool inclZero) {
    std::cout << "Enter " << name << std::endl;
    std::string numberStr;
    int number;
    std::getline(std::cin, numberStr);
    number = atoi(numberStr.c_str());
    int threshold = (inclZero) ? 0 : 1;
    while (number < threshold) {
        std::cout << "Enter a valid non-negative integer\n";
        std::getline(std::cin, numberStr);
        number = atoi(numberStr.c_str());
    }
    return number;
}

bool enterFireplace(const std::string& name) {
    std::string numberStr = "";
    do {
        std::cout << "Does " << name << " have a fireplace? (y/n)\n";
        std::getline(std::cin, numberStr);
    } while (numberStr != "y" && numberStr != "n");
    return (numberStr == "y");
}

RoomType enterRoomType(const std::string& name) {
    std::string roomTypeStr;
    RoomType type = UNDEFINED;
    do {
        std::cout << "Enter the type of " << name << std::endl;
        std::cout << "(bedroom/kitchen/bathroom/playing_room/living_room)" << std::endl;
        std::getline(std::cin, roomTypeStr);
        type = (roomTypeStr != "bedroom") ? BEDROOM :
               (roomTypeStr != "kitchen") ? KITCHEN :
               (roomTypeStr != "bathroom") ? BATHROOM :
               (roomTypeStr != "playing_room") ? PLAYING_ROOM :
               (roomTypeStr != "living_room") ? LIVING_ROOM : UNDEFINED;
    } while (type == UNDEFINED);
    return type;
}


void initRoom (Room &room, const std::string& name) {
    room.area = enterFloatPos("the area of " + name);
    room.type = enterRoomType(name);
}

void initStage (Stage &stage, const std::string& name) {
    stage.height = enterFloatPos("the height of " + name);
    int roomsCount = enterInt("the number of rooms on " + name, false);
    for (int i = 1; i <= roomsCount; i++) {
        Room room;
        initRoom(room, "room #" + std::to_string(i));
        stage.rooms.push_back(room);
    }
}

void initHouse(House &house, const std::string& name) {
    house.area = enterFloatPos("the area of " + name);
    house.hasFireplace = enterFireplace(name);
    int stagesCount = enterInt("the number of stages in " + name, false);
    for (int i = 1; i <= stagesCount; i++) {
        Stage stage;
        initStage(stage, "house #" + std::to_string(i));
        house.stages.push_back(stage);
    }
}

void initGarage(Garage &garage, const std::string& name) {
    garage.area = enterFloatPos("the area of " + name);
}

void initShed(Shed &shed, const std::string& name) {
    shed.area = enterFloatPos("the area of " + name);
}

void initBathhouse(Bathhouse &bathhouse, const std::string& name) {
    bathhouse.area = enterFloatPos("the area of " + name);
    bathhouse.hasFireplace = enterFireplace(name);
}

void initHomeStead(Homestead &homestead, const std::string& name) {
    int housesCount = enterInt("the number of living houses in " + name, false);
    int garagesCount = enterInt("the number of garages in " + name, true);
    int shedsCount = enterInt("the number of sheds in " + name, true);
    int bathhousesCount = enterInt("the number of bathhouses in " + name, true);
    for (int i = 1; i <= housesCount; i++) {
        House house;
        initHouse(house, "house #" + std::to_string(i));
        homestead.houses.push_back(house);
    }
    for (int i = 1; i <= garagesCount; i++) {
        Garage garage;
        initGarage(garage, "garage #" + std::to_string(i));
        homestead.garages.push_back(garage);
    }
    for (int i = 1; i <= shedsCount; i++) {
        Shed shed;
        initShed(shed, "shed #" + std::to_string(i));
        homestead.sheds.push_back(shed);
    }
    for (int i = 1; i <= bathhousesCount; i++) {
        Bathhouse bathhouse;
        initBathhouse(bathhouse, "garage #" + std::to_string(i));
        homestead.bathhouses.push_back(bathhouse);
    }
}

void initVillage(Village &village) {
    village.area = enterFloatPos("the area of village");
    int homesteadsCount = enterInt("the number of homesteads in the village", false);
    for (int i = 1; i <= homesteadsCount; i++) {
        Homestead homestead;
        initHomeStead(homestead, "homestead #" + std::to_string(i));
        village.homesteads.push_back(homestead);
    }
}

float buildingsToVillageAreaRatio (const Village &village) {
    float buildingsTotalArea = 0;
    for (const auto& homestead : village.homesteads) {
        for (const auto& house : homestead.houses)
            buildingsTotalArea += house.area;
        for (const auto& garage : homestead.garages)
            buildingsTotalArea += garage.area;
        for (const auto& shed : homestead.sheds)
            buildingsTotalArea += shed.area;
        for (const auto& bathhouse : homestead.bathhouses)
            buildingsTotalArea += bathhouse.area;
    }
    return buildingsTotalArea / village.area;
}

int main() {
    Village village;
    initVillage(village);
    std::cout << "The buildings to village area ratio is " << buildingsToVillageAreaRatio(village) << std::endl;
    return 0;
}
