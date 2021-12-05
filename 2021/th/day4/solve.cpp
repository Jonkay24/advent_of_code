// TH 2021
#include <iostream>
#include <list>
#include <vector>

#include "include/utils.h"

class Board {

};

int main() {
    std::vector<std::string> input = readFileLines("example.txt");
    std::vector<int> ints;
    std::cout << input[0] << std::endl;
    extractIntsFromCommaString(input[0], &ints);

    for (const auto& i : ints) {
        std::cout << i << std::endl;
    }

    // Get first string ints, then loop through boards and load into a vector of unordered maps
    // Then play the game and check the state of each board (map gives O(1) lookup time)
    // Could be vector of new Board class - board class contains the map and a state (the sums of each column/row) (then don't need to sum them all the time)
}
