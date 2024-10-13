#include <iostream>
#include <vector>

using namespace std;

// Function to print the N-Queens matrix (board)
void printBoard(vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Function to check if placing a queen on board[row][col] is safe
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check this row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) return false;
    }

    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check the lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueensUtil(vector<vector<int>>& board, int col, int N) {
    // If all queens are placed, return true
    if (col >= N) return true;

    // Consider this column and try placing queens in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if it's safe to place a queen at board[i][col]
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1; // Place the queen

            // Recur to place the rest of the queens
            if (solveNQueensUtil(board, col + 1, N))
                return true;

            // If placing the queen at board[i][col] leads to a solution, return true
            board[i][col] = 0; // Backtrack (remove the queen)
        }
    }

    // If the queen can't be placed in any row for this column, return false
    return false;
}

// Function to solve the N-Queens problem with the first queen placed at (row, col)
bool solveNQueens(int N, int firstRow, int firstCol) {
    // Initialize the board with 0s (no queens placed)
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Place the first queen at the given position
    board[firstRow][firstCol] = 1;

    // Solve the rest of the board
    if (!solveNQueensUtil(board, 0, N)) {
        cout << "No solution exists" << endl;
        return false;
    }

    // Print the final N-Queens matrix
    printBoard(board, N);
    return true;
}

int main() {
    int N, firstRow, firstCol;

    cout << "Enter the size of the board (N): ";
    cin >> N;
    cout << "Enter the row and column where the first queen is placed (0-indexed): ";
    cin >> firstRow >> firstCol;

    if (solveNQueens(N, firstRow, firstCol)) {
        cout << "Solution exists and the final N-Queens matrix is displayed above." << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
