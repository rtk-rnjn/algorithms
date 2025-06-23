// 79.c Word Search

#include <stdio.h>
#include <stdbool.h>


bool dfs(char board[6][6], int boardSize, int *boardColSize, char *word, int wordIndex, int row, int col)
{
    if (word[wordIndex] == '\0')
    {
        return true;
    }

    if (row < 0 || row >= boardSize || col < 0 || col >= (*boardColSize) || board[row][col] != word[wordIndex])
    {
        return false;
    }

    char temp = board[row][col];
    board[row][col] = '#';

    bool found = dfs(board, boardSize, boardColSize, word, wordIndex + 1, row + 1, col) ||
                 dfs(board, boardSize, boardColSize, word, wordIndex + 1, row - 1, col) ||
                 dfs(board, boardSize, boardColSize, word, wordIndex + 1, row, col + 1) ||
                 dfs(board, boardSize, boardColSize, word, wordIndex + 1, row, col - 1);

    board[row][col] = temp;
    return found;
}

bool exist(char board[6][6], int boardSize, int *boardColSize, char *word)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < (*boardColSize); j++)
        {
            if (dfs(board, boardSize, boardColSize, word, 0, i, j))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    char board[6][6] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
        {'A', 'B', 'C', 'D'},
        {'A', 'B', 'C', 'E'},
        {'A', 'B', 'C', 'F'}
    };

    int boardColSize = 4;
    char word[] = {'A', 'B', 'C', 'E', '\0'}; 
    bool result = exist(board, 3, &boardColSize, word);

    printf("%s\n", result ? "true" : "false");
    return 0;
}
