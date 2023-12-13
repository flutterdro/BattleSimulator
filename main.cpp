#include <iostream>

#include "BattleSimulator.h"
#include <sstream>

int main() {
    int M, N;
    std::cin >> M >> N;
    BattleSimulator::initialize(M, N);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int height;
            std::cin >> height;
            BattleSimulator::setHeight(i, j, height);
        }
    }

    std::cin.ignore(); // Ignore newline after reading N

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream lineStream(line);
        unsigned int currentTime = BattleSimulator::currentTime;
        std::string commands;

        // Read time and rest of the line
        if (lineStream >> currentTime) {
            std::getline(lineStream >> std::ws, commands); // Read the remaining line as commands, skipping whitespace

            // Update state for the current time
            BattleSimulator::updateState(currentTime);

            // Split commands by ';'
            std::istringstream commandStream(commands);
            std::string command;
            while (std::getline(commandStream, command, ';')) {
                if (!command.empty()) {
                    // Trim leading spaces if any
                    auto start = command.find_first_not_of(" \t");
                    if (start != std::string::npos) {
                        command = command.substr(start);
                    }

                    // Process each command
                    BattleSimulator::processCommand(command);
                }
            }
        }


    }


    delete BattleSimulator::board;  // Clean up allocated resources

    return 0;
}



