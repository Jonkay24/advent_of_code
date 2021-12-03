// TH 2021
#include <iostream>
#include <vector>

#include "include/utils.h"

// TODO(TH): comment more to help people learn syntax

int main() {
    std::vector<int> input;

    ReadFile("input.txt", &input);

    int result = 0;
    int prev = input[0];
    for (const auto line : input) {
        if (line > prev) {
            result++;
        }
        prev = line;
    }

    int result2 = 0;
    if (input.size() > 3) {
        int curr = input[0] + input[1] + input[2];
        int prev = curr;
        for (int i = 3; static_cast<size_t>(i) < input.size(); ++i) {
            prev = curr;
            curr -= input[i-3];
            curr += input[i];
            if (curr > prev) {
                result2++;
            }
        }
    }

    printf("There are %u measurements greater than the previous measurement.\n", result);
    printf("There are %u 3-sums larger than the previous one.\n", result2);
}
