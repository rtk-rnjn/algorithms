from __future__ import annotations


class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        def is_valid(board, row, col):
            for i in range(row):
                if board[i] == col or board[i] - i == col - row or board[i] + i == col + row:
                    return False
            return True

        def backtrack(board, row):
            if row == n:
                res.append(["." * i + "Q" + "." * (n - i - 1) for i in board])
                return
            for col in range(n):
                if is_valid(board, row, col):
                    board[row] = col
                    backtrack(board, row + 1)
                    board[row] = -1

        res = []
        board = [-1] * n
        backtrack(board, 0)
        return res


if __name__ == "__main__":
    n = 4
    sol = Solution()
    print(sol.solveNQueens(n))
