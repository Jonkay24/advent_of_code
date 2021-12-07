// TH 2021
#include <cstdint>
#include <iostream>
#include <vector>

#include "include/utils.h"

int main() {
    std::vector<std::string> input = readFileLines("input.txt");
    std::vector<int> start_timers;
    extractIntsFromCommaString(input[0], &start_timers);

    uint64_t prev_timers[9] = {0};
    uint64_t next_timers[9] = {0};

    for (auto timer : start_timers) {
        prev_timers[timer]++;
    }

    for (int i=0; i < 256; ++i) {
        for (int j=0; j < 9; ++j) {
            if (j == 0) {
                next_timers[6] = prev_timers[j];
                next_timers[8] = prev_timers[j];
            } else if (j == 7) {
                next_timers[j-1] += prev_timers[j];
            } else {
                next_timers[j-1] = prev_timers[j];
            }
        }

        for (int j=0; j < 9; ++j) {
            prev_timers[j] = next_timers[j];
        }

        if (i == 79) {
            uint64_t sum = 0;
            for (int i=0; i < 9; ++i) {
                sum += next_timers[i];
            }

            std::cout << "===== PART 1 =====" << std::endl;
            std::cout << "Answer: " << sum << std::endl;
        }
    }

    uint64_t sum = 0;

    for (int i=0; i < 9; ++i) {
        sum += next_timers[i];
    }

    std::cout << "===== PART 2 =====" << std::endl;
    std::cout << "Answer: " << sum << std::endl;

    return 0;
}
