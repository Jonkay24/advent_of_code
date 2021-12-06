// TH 2021
#include <iostream>
#include <unordered_map>
#include <vector>

#include "include/utils.h"

class Board {
 private:
    std::unordered_map<int, std::pair<int, int>> pos;  // map value to position
    int cols[5] = {0};  // column sums
    int rows[5] = {0};  // row sums
    int rows_offset[5] = {0};

 public:
    bool has_won = false;

    explicit Board(const std::vector<std::vector<int>>& board) {
        for (int i=0; i < 5; ++i) {
            for (int j=0; j < 5; ++j) {
                // Sum up row
                rows[i] += board[i][j];
                // Add nums to column sums
                cols[j] += board[i][j];
                // Add pos to map
                pos[board[i][j]] = std::make_pair(i, j);
            }
        }
    }

    void Play(int value) {
        // Find coords of value if it's on the board
        auto it = pos.find(value);

        // If it's on the board, take it away
        if (it != pos.end()) {
            rows[it->second.first] -= value+1;
            rows_offset[it->second.first] += 1;
            cols[it->second.second] -= value+1;
        }
    }

    int Sum() const {
        int sum = 0;
        for (int i=0; i < 5; i++) {
            sum += rows[i] + rows_offset[i];
        }
        return sum;
    }

    bool Check() const {
        // Check if any row/col sums to 0
        for (int i=0; i < 5; i++) {
            if (cols[i] == -5 || rows[i] == -5)
                return true;
        }
        return false;
    }
};

int main() {
    std::vector<std::string> input = readFileLines("input.txt");
    std::vector<int> nums;

    extractIntsFromCommaString(input[0], &nums);

    std::vector<Board> boards;

    for (int i = 2; static_cast<size_t>(i) < input.size(); i+=6) {
        std::vector<std::vector<int>> board;
        for (int j = i; j < i+5; ++j) {
            std::vector<int> row;
            extractIntsFromString(input[j], &row);
            board.push_back(row);
        }
        boards.push_back(Board(board));
    }

    int first_win = false;
    int wins = 0;
    for (auto num : nums) {
        for (auto& board : boards) {
            board.Play(num);
            if (board.Check()) {
                if (!first_win) {
                    first_win = true;
                    std::cout << "===== PART 1 =====" << std::endl;
                    std::cout << "Winning score: " << board.Sum() * num << std::endl;
                }
                if (static_cast<size_t>(wins) == boards.size() - 1 && !board.has_won) {
                    std::cout << "===== PART 2 =====" << std::endl;
                    std::cout << "Final winning score: " << board.Sum() * num << std::endl;
                    return 0;
                }
                if (!board.has_won) {
                    board.has_won = true;
                    wins++;
                }
            }
        }
    }

    std::cout << "Error" << std::endl;
    return 1;
}
