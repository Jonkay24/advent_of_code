// TH 2021
#include <iostream>
#include <list>
#include <vector>

#include "include/utils.h"

int MostCommonBit(const std::list<int>& nums, int bit_idx) {
    // Where bit_idx 0 = LSB
    int sum = 0;
    for (const auto& num : nums) {
        sum += (num & (1 << bit_idx)) >> bit_idx;
    }

    return static_cast<size_t>(sum) >= (nums.size() + 1) / 2;
}

int main() {
    std::vector<std::string> input = ReadFileLines("input.txt");

    std::list<int> ints;

    for (const auto& line : input) {
        // Convert binary string to integer
        ints.push_back(std::stoi(line, nullptr, 2));
    }

    int length = input[0].length();

    // Part 1

    int gamma = 0;
    int epsilon = 0;
    for (int i=0; i<length; ++i) {
        if (MostCommonBit(ints, i)) {
            gamma |= 1 << i;
        } else {
            epsilon |= 1 << i;
        }
    }

    std::cout << "===== Part 1 =====" << std::endl;
    std::cout << "Gamma: " << gamma << std::endl;
    std::cout << "Epsilon: " << epsilon << std::endl;
    std::cout << "Answer: " << gamma * epsilon << std::endl;

    // Part 2
    
    // Oxygen
    std::list<int> oxy = ints;
    for (int i = length-1; oxy.size() > 1 && i >= 0; --i) {
        int mcb = MostCommonBit(oxy, i);
        for (auto it = oxy.begin(); oxy.size() > 1 && it != oxy.end(); ) {
            if ( ((*it & (1 << i)) >> i) != mcb ) {
                it = oxy.erase(it);
            } else{
                ++it;
            }
        }
    } 

    // CO2
    std::list<int> co2 = ints;
    for (int i = length-1; co2.size() > 1 && i >= 0; --i) {
        int mcb = MostCommonBit(co2, i);
        for (auto it = co2.begin(); co2.size() > 1 && it != co2.end(); ) {
            if ( ((*it & (1 << i)) >> i) == mcb ) {
                it = co2.erase(it);
            } else{
                ++it;
            }
        }
    }  

    std::cout << "===== Part 2 =====" << std::endl;
    std::cout << "Oxygen: " << oxy.front() << std::endl;
    std::cout << "CO2: " << co2.front() << std::endl;
    std::cout << "Answer: " << oxy.front() * co2.front() << std::endl;
}
