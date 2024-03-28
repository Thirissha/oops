#include <iostream>
#include <vector>

bool isSafe(std::vector<std::vector<int>>& board, int row, int col, int n) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(std::vector<std::vector<int>>& board, int row, int n) {
    if (row == n) {
        return true; // All queens are successfully placed
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1; // Place the queen

            // Recur to place the remaining queens
            if (solveNQueensUtil(board, row + 1, n)) {
                return true;
            }

            // If placing queen in (row, col) doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    return false; // No solution found
}

void solveNQueens(int n) {
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));

    if (solveNQueensUtil(board, 0, n)) {
        // Print the solution
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No solution exists for the N Queens problem." << std::endl;
    }
}

int main() {
    int n = 4;
    solveNQueens(n);
    return 0;
}
