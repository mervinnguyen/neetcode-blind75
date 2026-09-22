/**
 * @file ValidSudoku.cpp
 * @brief Implementation of a Sudoku validation algorithm using bitmasks.
 * @author Mervin Nguyen
 * @date 2026-09-21
 * @version 1.0.0
 *
 * Approach:
 * - The board is a fixed 9x9 grid, so a single pass over all 81 cells is O(1)
 *   time and O(1) space (no growth with input beyond the fixed board size).
 * - Track seen digits per row, per column, and per 3x3 box using a 9-bit
 *   mask each (bit d-1 set means digit d has been seen).
 * - For each filled cell, compute its box index as (r/3)*3 + (c/3), then
 *   check/set the corresponding bit in the row, col, and box masks.
 * - If the bit is already set in any of the three, there's a duplicate.
 *
 * Time: O(1) - exactly 81 cell visits.
 * Space: O(1) - 9 row masks + 9 col masks + 9 box masks.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool is_valid_sudoku(vector<vector<char>> &board) {
        int row_mask[9] = {};
        int col_mask[9] = {};
        int box_mask[9] = {};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') continue;

                int bit = 1 << (ch - '1');
                int box_index = (r / 3) * 3 + (c / 3);

                if ((row_mask[r] & bit) || (col_mask[c] & bit) || (box_mask[box_index] & bit)) {
                    return false;
                }

                row_mask[r] |= bit;
                col_mask[c] |= bit;
                box_mask[box_index] |= bit;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << boolalpha << sol.is_valid_sudoku(board) << endl; // expected: true
}