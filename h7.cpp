#include <iostream>
#include <vector>

const int BOARD_SIZE = 9;
const int SUBGRID_SIZE = 3;

bool isValid(std::vector<std::vector<char>>& board, int row, int col, char num) {
    // Check row and column
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check subgrid
    int subgridRowStart = (row / SUBGRID_SIZE) * SUBGRID_SIZE;
    int subgridColStart = (col / SUBGRID_SIZE) * SUBGRID_SIZE;
    for (int i = subgridRowStart; i < subgridRowStart + SUBGRID_SIZE; ++i) {
        for (int j = subgridColStart; j < subgridColStart + SUBGRID_SIZE; ++j) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(std::vector<std::vector<char>>& board) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; ++num) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[row][col] = '.'; // Backtrack
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true; // No empty cell, puzzle solved
}

void printBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (solveSudoku(board)) {
        std::cout << "Sudoku puzzle solved successfully:" << std::endl;
        printBoard(board);
    } else {
        std::cout << "No solution exists for the Sudoku puzzle." << std::endl;
    }

    return 0;
}
