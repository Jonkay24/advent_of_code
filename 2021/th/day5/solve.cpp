// TH 2021
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

#include "include/utils.h"

// TODO(TH): Simplify this approach, bit of a mess
struct Coordinate {
    int x, y;
    Coordinate(int x, int y) : x(x), y(y) {}

    bool operator<(const Coordinate& coord) const {
        // TODO(TH): Look up std::tie, structured bindings etc
        return std::tie(x, y) < std::tie(coord.x, coord.y);
    }

    bool operator==(const Coordinate& coord) const {
        return (x == coord.x && y == coord.y);
    }

    struct HashFunction {
        size_t operator()(const Coordinate& coord) const {
            size_t x_hash = std::hash<int>()(coord.x);
            size_t y_hash = std::hash<int>()(coord.y) << 1;
            return x_hash ^ y_hash;
        }
    };
};

int markCoords(Coordinate c1, Coordinate c2, std::unordered_map<Coordinate, int, Coordinate::HashFunction>* coords) {
    int overlaps = 0;
    bool stop = false;

    while (!stop) {
        if (c1.x == c2.x && c1.y == c2.y)
            stop = true;

        auto it = coords->find(c1);

        if (it != coords->end()) {
            if (it->second == 1)
                overlaps++;
            it->second += 1;
        } else {
            coords->insert(std::make_pair(c1, 1));
        }

        if (c1.x < c2.x)
            c1.x++;
        if (c2.x < c1.x)
            c1.x--;
        if (c1.y < c2.y)
            c1.y++;
        if (c2.y < c1.y)
            c1.y--;
    }

    return overlaps;
}

int main() {
    std::vector<std::string> input = readFileLines("input.txt");
    std::vector<std::vector<int>> lines;

    for (size_t i=0; i < input.size(); ++i) {
        lines.push_back({});
        extractIntsFromCommaString(input[i], &lines[i]);
    }

    std::unordered_map<Coordinate, int, Coordinate::HashFunction> coords;

    int overlap = 0;

    for (const auto& line : lines) {
        // Ignore diagonals for now
        if (line[0] != line[2] && line[1] != line[3])
            continue;

        overlap += markCoords(Coordinate(line[0], line[1]), Coordinate(line[2], line[3]), &coords);
    }

    std::cout << "===== PART 1 =====" << std::endl;
    std::cout << "Answer: " << overlap << std::endl;

    for (const auto& line : lines) {
        // Process diagonals
        if (line[0] != line[2] && line[1] != line[3])
            overlap += markCoords(Coordinate(line[0], line[1]), Coordinate(line[2], line[3]), &coords);
    }

    std::cout << "===== PART 2 =====" << std::endl;
    std::cout << "Answer: " << overlap << std::endl;
}
