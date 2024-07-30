// 36. Valid Sudoku

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_valid(char **board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
        {
            return false;
        }
        if (board[row][i] == c)
        {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        {
            return false;
        }
    }
    return true;
}

bool isValidSudoku(char **board, int boardSize)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                if (!is_valid(board, i, j, board[i][j]))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    char **board = (char **)malloc(9 * sizeof(char *));
    for (int i = 0; i < 9; i++)
    {
        board[i] = (char *)malloc(9 * sizeof(char));
    }
    int boardSize = 9;

    board[0] = "53..7....";
    board[1] = "6..195...";
    board[2] = ".98....6.";
    board[3] = "8...6...3";
    board[4] = "4..8.3..1";
    board[5] = "7...2...6";
    board[6] = ".6....28.";
    board[7] = "...419..5";
    board[8] = "....8..79";

    printf("%d\n", isValidSudoku(board, boardSize));

    return 0;
}