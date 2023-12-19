#include <iostream>

#include "BattleSimulator.h"
#include <sstream>

int main() {
    int M, N;
    std::cin >> M >> N;
    BattleSimulator* sim = new BattleSimulator(M, N);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int height;
            std::cin >> height;
            sim->setHeight(i, j, height);
        }
    }

    std::cin.ignore(); // Ignore newline after reading N

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream lineStream(line);
        unsigned int currentTime = sim->currentTime;
        std::string commands;

        // Read time and rest of the line
        if (lineStream >> currentTime) {
            std::getline(lineStream >> std::ws, commands); // Read the remaining line as commands, skipping whitespace

            // Update state for the current time
            sim->updateState(currentTime);

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
                    sim->processCommand(command);
                }
            }

            // Update state for the current time
            sim->updateState(currentTime);
        }


    }
    return 0;
}



