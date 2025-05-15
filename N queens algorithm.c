#include <stdio.h>
#include <stdbool.h>

#define N 8

void printSolution(int board[N][N]) {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%s ", board[i][j] ? "Q" : ".");
        }
        printf("\n");
    }
}


bool isSafe(int board[N][N], int row, int col) {

    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;


    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;


    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}


bool solveNQueens(int board[N][N], int row) {
    if (row >= N) {
        printSolution(board);
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1))
                return true;

            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int board[N][N] = {0};

    if (!solveNQueens(board, 0))
        printf("No solution exists for N = %d\n", N);

    return 0;
}
