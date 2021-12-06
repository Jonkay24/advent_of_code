// TH 2021
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "utils.h"


std::vector<std::string> readFileLines(std::string path) {
    std::vector<std::string> input;
    std::string line;
    std::ifstream infile(path);

    while (std::getline(infile, line)) {
        input.push_back(line);
    }

    return input;
}

// Vectors can be large so we pass by reference
std::vector<int> vecStringToInt(const std::vector<std::string>& string_vec) {
    std::vector<int> int_vec;

    for (const auto& s : string_vec) {
        int_vec.push_back(std::stoi(s));
    }

    return int_vec;
}

void extractIntsFromCommaString(const std::string& str, std::vector<int>* out) {
    std::stringstream ss(str);

    int i;

    while (ss >> i) {
        out->push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
    }
}

void extractIntsFromString(const std::string& str, std::vector<int>* out) {
    std::stringstream ss;

    ss << str;

    std::string temp;
    int found;
    while (!ss.eof()) {
        ss >> temp;

        if (std::stringstream(temp) >> found)
            out->push_back(found);

        temp = "";
    }
}
