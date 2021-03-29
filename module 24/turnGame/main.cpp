#include <iostream>
#include <string>
#include <vector>
#include <fstream>

const int boardSize = 40;

enum GameState {
    PLAYING,
    GAME_OVER
};

// ***** STRUCTS ***** //
struct Coords {
    int x = rand() % boardSize;
    int y = rand() % boardSize;
};

struct Character {
    std::string name = "Unknown";
    int health = 50 + rand() % 101;
    int armor = rand() % 51;
    int damage = 15 + rand() % 16;
    Coords coords;
};

struct GameData {
    Character player;
    std::vector<Character> enemies;
};

// ***** FUNCTIONS ***** //
// SIMPLE FUNCTIONS
bool areCoordEqual(Coords a, Coords b) {
    return (a.x == b.x && a.y == b.y);
}

Coords move(Coords coords, Coords shift) {
    return {coords.x+shift.x, coords.y+shift.y};
}

int enterIntPos(const std::string& name) {
    std::string input;
    std::cout << name << ":\n" << std::endl;
    getline(std::cin, input);
    int output = atoi(input.c_str());
    while (output <= 0) {
        std::cout << "Enter " << name << " greater than zero:\n";
        getline(std::cin, input);
        output = atoi(input.c_str());
    }
    return output;
}

// checkCoords checks if the specified coordinates are valid, i.e. inside board and are not occupied.
bool checkCoords(const GameData& gameData, Coords coords) {
    for (const auto& enemy : gameData.enemies)
        if (areCoordEqual(enemy.coords, coords))
            return false;
    return (coords.x >=0 &&
            coords.y >=0 &&
            coords.x < boardSize &&
            coords.y < boardSize &&
            !areCoordEqual(gameData.player.coords, coords));
}

// DRAWING FUNCTIONS
std::string initBoard() {
    std::string boardLine = (std::string(boardSize, '.') + "\n");
    std::string board;
    for (int i = 0; i < boardSize; i++)
        board += boardLine;
    return board;
}

void drawBoard(std::string board, const Character& player, const std::vector<Character>& enemies) {
    board[(boardSize + 1) * player.coords.y + player.coords.x] = (player.health <= 0) ? 'X' : 'P';
    for (const auto& enemy : enemies)
        board[(boardSize + 1) * enemy.coords.y + enemy.coords.x] = 'E';
    std::cout << board;
}

// GAMEPLAY FUNCTIONS
// tryHitCharacter applies damage to the character if he is located at the specified coordinates.
void tryHitCharacter(Character &character, Coords coords, int damage) {
    if (areCoordEqual(character.coords, coords)) {
        character.armor -= damage;
        if (character.armor < 0) {
            character.health += character.armor;
            character.armor = 0;
        }
    }
}

// movePlayer changes the player position if possible, controls player hits.
GameState movePlayer (GameData &gameData, std::string command) {
    auto &player = gameData.player;
    auto &enemies = gameData.enemies;
    Coords playerCoords = player.coords;

    // Move player
    while (true) {
        if (command == "w") {
            playerCoords = move(playerCoords, {0,-1});
            break;
        } else if (command == "a") {
            playerCoords = move(playerCoords, {-1,0});
            break;
        } else if (command == "s") {
            playerCoords = move(playerCoords, {0,1});
            break;
        } else if (command == "d") {
            playerCoords = move(playerCoords, {1,0});
            break;
        } else {
            std::cout << "Incorrect command. Move using (w/a/s/d)\n";
            std::cin >> command;
        }
    }

    // Check if hit wall or enemy
    if (checkCoords(gameData, playerCoords)) {
        player.coords = playerCoords;
    } else {
        for (int i = 0; i < enemies.size(); i++) {
            tryHitCharacter(enemies[i], playerCoords, player.damage);
            if (enemies[i].health <= 0) {
                enemies.erase(enemies.begin() + i);
                break;
            }
        }
    }

    return (enemies.empty()) ? GAME_OVER : PLAYING;
}

// moveEnemies the enemies positions if possible, controls enemy hits.
GameState moveEnemies (GameData &gameData) {
    auto &player = gameData.player;
    auto &enemies = gameData.enemies;
    const Coords shifts[] = {{0,-1}, {-1,0}, {0,1}, {1,0}};

    for (auto &enemy : enemies) {

        // Move enemy
        Coords enemyCoords = enemy.coords;
        enemyCoords = move(enemyCoords, shifts[rand() % 4]);

        // Check if hit wall or player
        if (checkCoords(gameData, enemyCoords))
            enemy.coords = enemyCoords;
        else
            tryHitCharacter(player, enemyCoords, enemy.damage);
    }
    return (player.health <= 0) ? GAME_OVER : PLAYING;
}

// SAVING AND LOADING GAME
void saveCharacter(std::ofstream &outGameFile, const Character &character) {
    int len = character.name.length();
    outGameFile.write((char*)&len, sizeof(len));
    outGameFile.write(character.name.c_str(), len);
    outGameFile.write((char*)&character.health, sizeof(character.health));
    outGameFile.write((char*)&character.armor, sizeof(character.armor));
    outGameFile.write((char*)&character.damage, sizeof(character.damage));
    outGameFile.write((char*)&character.coords.x, sizeof(character.coords.x));
    outGameFile.write((char*)&character.coords.y, sizeof(character.coords.y));
}

void loadCharacter(std::ifstream &inGameFile, Character &character) {
    int len;
    inGameFile.read((char*)&len, sizeof(len));
    character.name.resize(len);
    inGameFile.read((char*)character.name.c_str(), len);
    inGameFile.read((char*)&character.health, sizeof(character.health));
    inGameFile.read((char*)&character.armor, sizeof(character.armor));
    inGameFile.read((char*)&character.damage, sizeof(character.damage));
    inGameFile.read((char*)&character.coords.x, sizeof(character.coords.x));
    inGameFile.read((char*)&character.coords.y, sizeof(character.coords.y));
}

void saveGame(std::ofstream &outGameFile, const GameData &gameData) {
    saveCharacter(outGameFile, gameData.player);
    int enemiesCount = gameData.enemies.size();
    outGameFile.write((char*)&enemiesCount, sizeof(enemiesCount));
    for (const auto& enemy : gameData.enemies) {
        saveCharacter(outGameFile, enemy);
    }
}

void loadGame(std::ifstream &inGameFile, GameData &gameData) {
    loadCharacter(inGameFile, gameData.player);
    int enemiesCount;
    inGameFile.read((char*)&enemiesCount, sizeof(enemiesCount));
    gameData.enemies.resize(enemiesCount);
    for (int i = 0; i < enemiesCount; i++) {
        loadCharacter(inGameFile, gameData.enemies[i]);
    }
}

int main() {
    srand(time(nullptr));
    const int enemiesCount = 5;
    GameData gameData;
    auto &player = gameData.player;
    gameData.enemies.resize(enemiesCount);
    auto &enemies = gameData.enemies;

    std::cout << "Welcome to Turn Game!\n\n"
                 "Custom your character:\n" << std::endl;

    std::cout << "Name:\n" << std::endl;
    getline(std::cin, player.name);
    player.health = enterIntPos("Health");
    player.armor = enterIntPos("Armor");
    player.damage = enterIntPos("Damage");

    for (int i = 0; i < enemiesCount; i++)
        enemies[i].name = "Enemy" + std::to_string(i + 1);

    std::string board = initBoard();
    std::string output = "\n";
    drawBoard(board, player, enemies);

    while (true) {
        std::cout << "Your turn, " << player.name << "! [+" << player.health << " *" << player.armor <<
                     "] Move using (w/a/s/d).\nEnter \"save\" to save game, \"load\' to load game.\n";
        std::string command;
        getline(std::cin, command);

        if (command == "save") {
            // Save game
            std::cout << "Enter path to save file:\n";
            getline(std::cin, command);
            std::ofstream outGameFile(command, std::ios::binary);
            if (!outGameFile.is_open()) {
                std::cout << "Failed to open the file.\n";
            } else {
                saveGame(outGameFile, gameData);
                outGameFile.close();
                std::cout << "Game saved!\n";
            }
        } else if (command == "load") {
            // Load game
            std::cout << "Enter path to the file:\n";
            getline(std::cin, command);
            std::ifstream inGameFile(command, std::ios::binary);
            if (!inGameFile.is_open()) {
                std::cout << "Failed to open the file.\n";
            } else {
                loadGame(inGameFile, gameData);
                inGameFile.close();
                std::cout << "Game loaded!\n";
            }
        } else {
            // Take turn
            if (movePlayer(gameData, command) == GAME_OVER) {
                output = "\n *** Player " + player.name + " WINS! *** \n";
                break;
            }
            if (moveEnemies(gameData) == GAME_OVER) {
                output = "\n *** Player " + player.name + " LOSES! *** \n";
                break;
            }
        }

        drawBoard(board, player, enemies);
    }
    drawBoard(board, player, enemies);
    std::cout << output;
    return 0;
}
