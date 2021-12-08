// TH 2021
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include "include/utils.h"

int main() {
    std::vector<std::string> input = readFileLines("input.txt");
    std::vector<int> pos;
    extractIntsFromCommaString(input[0], &pos);

    std::sort(pos.begin(), pos.end());

    // Part 1
    int mid = pos.size() / 2;

    if (pos.size() % 2)
        mid++;

    int res = 0;

    for (auto num : pos) {
        res += abs(pos[mid] - num);
    }


    std::cout << "===== PART 1 =====" << std::endl;
    std::cout << "Answer: " << res << std::endl;

    // Part 2
    double avg = 0;
    for (auto num : pos) {
        avg += num;
    }

    avg = floor(avg / pos.size());

    res = 0;

    double steps = 0;
    for (auto num : pos) {
        steps = abs(num - avg);
        res += steps*(1 + steps)/2;
    }

    std::cout << "===== PART 2 =====" << std::endl;
    std::cout << "Answer: " << res << std::endl;
}
