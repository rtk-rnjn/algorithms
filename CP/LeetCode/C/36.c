// 36. Valid Sudoku

#include <stdio.h>
#include <stdbool.h>

bool is_valid(const char **board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c || board[row][i] == c || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        {
            return false;
        }
    }
    return true;
}

bool isValidSudoku(const char **board)
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
    const char *board[9] = {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1",
                            "7...2...6", ".6....28.", "...419..5", "....8..79"};

    printf("%d\n", isValidSudoku(board));

    return 0;
}
