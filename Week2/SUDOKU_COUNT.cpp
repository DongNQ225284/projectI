#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 9;  // Size of the Sudoku grid

// Function to check if placing num in cell (row, col) is valid
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Check the row
    for (int j = 0; j < SIZE; ++j) {
        if (board[row][j] == num) return false;
    }

    // Check the column
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][col] == num) return false;
    }

    // Check the 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }

    return true;
}

// Recursive function to count solutions
int countSolutions(vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col] == 0) {  // Find an empty cell
                int solutionCount = 0;
                for (int num = 1; num <= SIZE; ++num) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;  // Place the number
                        solutionCount += countSolutions(board);  // Recur for next empty cell
                        board[row][col] = 0;  // Backtrack
                    }
                }
                return solutionCount;  // Return the count of solutions found
            }
        }
    }
    return 1;  // Found a complete solution
}

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE));

    // Input: Read the Sudoku board
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> board[i][j];
        }
    }

    // Count the number of solutions
    int solutionCount = countSolutions(board);
    cout << solutionCount << endl;

    return 0;
}
