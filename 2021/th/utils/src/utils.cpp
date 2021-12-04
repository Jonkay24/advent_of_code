// TH 2021
#include <fstream>
#include <string>
#include <vector>

#include "utils.h"


std::vector<std::string> ReadFileLines(std::string path) {
    std::vector<std::string> input;
    std::string line;
    std::ifstream infile(path);

    while (std::getline(infile, line)) {
        input.push_back(line);
    }

    return input;
}

// Vectors can be large so we pass by reference
std::vector<int> VecStringToInt(const std::vector<std::string>& string_vec) {
    std::vector<int> int_vec;

    for (const auto& s : string_vec) {
        int_vec.push_back(std::stoi(s));
    }

    return int_vec;
}
