// TH 2021
#include <fstream>
#include <string>
#include <vector>

#include "utils.h"

// I'm assuming input ints will be < 4 bytes
void ReadFile(std::string path, std::vector<int>* input) {
    std::string line;
    std::ifstream infile(path);

    while (std::getline(infile, line)) {
        input->push_back(std::stoi(line));
    }
}
