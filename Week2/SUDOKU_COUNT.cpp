/*
Problem: Count number of sudoku solutions

Description:
Write a program to compute the number of sudoku solutions (fill the zero elements of a given partial sudoku table)
Fill numbers from 1, 2, 3, .., 9 to 9 x 9 table so that:
Numbers of each row are distinct
Numbers of each column are distinct
Numbers on each sub-square 3 x 3 are distinct
Input
Each line i (i = 1, 2, ..., 9) contains elements of the i
th
 row of the Sudoku table: elements are numbers from 0 to 9 (value 0 means the empty cell of the table)
Output
Write the number of solutions found

Example
Input
0 0 3 4 0 0 0 8 9
0 0 6 7 8 9 0 2 3
0 8 0 0 2 3 4 5 6
0 0 4 0 6 5 0 9 7
0 6 0 0 9 0 0 1 4
0 0 7 2 0 4 3 6 5
0 3 0 6 0 2 0 7 8
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
Output
64
*/
#include <iostream>
#include <vector>
using namespace std;

#define SIZE 9

class Solution {
public:
    vector<vector<int>> board;
    int count = 0;

    int rowMask[SIZE]{};
    int colMask[SIZE]{};
    int blockMask[SIZE]{};

    int block_index(int r, int c) {
        return (r / 3) * 3 + (c / 3);
    }

    bool is_valid(int r, int c, int v) {
        int bit = 1 << v;
        int b = block_index(r, c);
        if (rowMask[r] & bit) return false;
        if (colMask[c] & bit) return false;
        if (blockMask[b] & bit) return false;
        return true;
    }

    void place_number(int r, int c, int v) {
        int bit = 1 << v;
        board[r][c] = v;
        rowMask[r] |= bit;
        colMask[c] |= bit;
        blockMask[block_index(r, c)] |= bit;
    }

    void remove_number(int r, int c, int v) {
        int bit = 1 << v;
        board[r][c] = 0;
        rowMask[r] &= ~bit;
        colMask[c] &= ~bit;
        blockMask[block_index(r, c)] &= ~bit;
    }

    // Backtracking
    void Try(int r, int c) {
        if (r == SIZE) {
            count++;
            return;
        }

        int next_r = (c == SIZE - 1) ? r + 1 : r;
        int next_c = (c == SIZE - 1) ? 0 : c + 1;

        if (board[r][c] != 0) {
            Try(next_r, next_c);
        } else {
            for (int v = 1; v <= SIZE; v++) {
                if (is_valid(r, c, v)) {
                    place_number(r, c, v);
                    Try(next_r, next_c);
                    remove_number(r, c, v);
                }
            }
        }
    }

    void solve(vector<vector<int>> board) {
        this->board = board;

        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                int v = board[r][c];
                if (v != 0) {
                    place_number(r, c, v);
                }
            }
        }

        Try(0, 0);
        cout << count << endl;
    }
};

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> board[i][j];
        }
    }
    Solution solution;
    solution.solve(board);
    return 0;
}
