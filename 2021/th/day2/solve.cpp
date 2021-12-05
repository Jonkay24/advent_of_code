// TH 2021
#include <iostream>
#include <vector>

#include "include/utils.h"

int main() {
    std::vector<std::string> input = ReadFileLines("input.txt");

    std::vector<std::pair<std::string, int>> pairs;

    // Split lines into pairs of strings and ints
    for (const auto& line : input) {
        pairs.push_back(std::make_pair(
            line.substr(0, line.find(" ")),
            std::stoi(line.substr(line.find(" ")+1, line.length()))
        ));
    }

    // Solve part 1
    int h_pos = 0;
    int depth = 0;

    for (const auto& pair : pairs) {
        if (pair.first == "forward") {
            h_pos += pair.second;
        } else {
            if (pair.first == "up")
                depth -= pair.second;
            if (pair.first == "down")
                depth += pair.second;
        }
    }

    std::cout << "Horizonal 1: " << h_pos << std::endl;
    std::cout << "Depth 1: " << depth << std::endl;
    std::cout << "Answer 1: " << h_pos * depth << std::endl;

    // Solve part 2
    h_pos = 0;
    depth = 0;
    int aim = 0;

    for (const auto& pair : pairs) {
        if (pair.first == "forward") {
            h_pos += pair.second;
            depth += aim * pair.second;
        } else {
            if (pair.first == "up")
                aim -= pair.second;
            if (pair.first == "down")
                aim += pair.second;
        }
    }

    std::cout << "Horizontal 2: " << h_pos << std::endl;
    std::cout << "Depth 2: " << depth << std::endl;
    std::cout << "Answer 2: " << h_pos * depth << std::endl;
}
