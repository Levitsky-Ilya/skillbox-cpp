#include <iostream>
#include <fstream>
#include <string>

// getText returns text from the file
// Prints error in cerr if reading from file is unsuccessful.
std::string getText(std::string path) {
    std::ifstream textStream;
    textStream.open(path);

    if (textStream.fail()) {
        std::cerr << "Error! File \"" << path << "\" cannot be opened!\n";
        return "";
    }

    char buffer [101];
    std::string text = "";
    while(!textStream.eof()) {
        textStream.read(buffer, sizeof(buffer) - 1);
        int symbolsRead = textStream.gcount();
        buffer[symbolsRead] = '\0';
        text += buffer;
    }

    textStream.close();
    return text;
}

// getQuestion returns text of question read from the file. Files are indexed.
std::string getQuestion(std::string path, int index) {
    return getText(path + "\\question" + std::to_string(index) + ".txt");
}

// getAnswer returns text of answer read from the file. Files are indexed.
std::string getAnswer(std::string path, int index) {
    return getText(path + "\\answer" + std::to_string(index) + ".txt");
}

int main() {
    std::cout << "\n**** Welcome to the Grand Quiz! ****\n\n" << std::endl;
    std::cout << "Before the game starts, enter path to question and answers folder:\n" << std::endl;
    std::string path;
    std::getline(std::cin, path);

    int sectors = 13;
    int tableSector = 0, playerPoints = 0, viewersPoints = 0;
    bool tableSectorSelected[] = {false, false, false, false, false, false,
                                  false, false, false, false, false, false, false};
    for (int round = 1; round <= sectors; round++) {
        int tableSectorShift;
        std::cout << "ROUND " << round << "\n Enter the random number: ";
        std::cin >> tableSectorShift;
        tableSectorShift %= sectors;
        tableSector = (tableSector + tableSectorShift + sectors) % sectors;
        while (tableSectorSelected[tableSector])
            tableSector = (tableSector + 1) % 13;
        tableSectorSelected[tableSector] = true;

        std::string question = getQuestion(path, tableSector);
        std::string correctAnswer = getAnswer(path, tableSector);
        if (question.empty()) {
            std::cout << "The game finishes due to an error.\n";
            return 0;
        }
        std::string answer;

        std::cout << "The sector " << tableSector << " is in game.\n";
        std::cout << question << "\n";

        // TODO check why first getline is skipped
        std::getline(std::cin, answer);
        std::getline(std::cin, answer);

        if (answer == correctAnswer) {
            playerPoints++;
            std::cout << "Correct! Player achieves 1 point.\n";
        } else {
            viewersPoints++;
            std::cout << "Wrong! The correct answer is " << correctAnswer << ". Viewers achieve 1 point.\n";
        }

        if (playerPoints == 6 || viewersPoints == 6)
            break;
        std::cout << "The score is " << playerPoints << ":" << viewersPoints << "\n\n";
    }

    std::cout << "\n\nWith score " << playerPoints << ":" << viewersPoints
              << ((playerPoints < viewersPoints) ? " viewers win!\n" : " player wins!\n");
}
