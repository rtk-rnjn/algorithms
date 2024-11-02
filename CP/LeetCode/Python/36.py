# 36. Valid Sudoku

from __future__ import annotations

import itertools


class Solution:
    def is_valid(self, arr: list[str]) -> bool:
        seen = set()
        for num in arr:
            if num == ".":
                continue
            if num in seen:
                return False
            seen.add(num)
        return True

    def isValidSudoku(self, board: list[list[str]]) -> bool:
        # Check rows
        for row in board:
            if not self.is_valid(row):
                return False

        # Check columns
        for col in range(9):
            column = [board[row][col] for row in range(9)]
            if not self.is_valid(column):
                return False

        # Check 3x3 boxes
        for i, j in itertools.product(range(0, 9, 3), range(0, 9, 3)):
            box = [board[x][y] for x in range(i, i + 3) for y in range(j, j + 3)]
            if not self.is_valid(box):
                return False

        return True


if __name__ == "__main__":
    board1 = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]
    assert Solution().isValidSudoku(board1) is True

    board2 = [
        ["8", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]
    assert Solution().isValidSudoku(board2) is False

    board3 = [
        [".", ".", ".", ".", "5", ".", ".", "1", "."],
        [".", "4", ".", "3", ".", ".", ".", ".", "."],
        [".", ".", ".", ".", ".", "3", ".", ".", "1"],
        ["8", ".", ".", ".", ".", ".", ".", "2", "."],
        [".", ".", "2", ".", "7", ".", ".", ".", "."],
        [".", "1", "5", ".", ".", ".", ".", ".", "."],
        [".", ".", ".", ".", ".", "2", ".", ".", "."],
        [".", "2", ".", "9", ".", ".", ".", ".", "."],
        [".", ".", "4", ".", ".", ".", ".", ".", "."],
    ]
    assert Solution().isValidSudoku(board3) is False
