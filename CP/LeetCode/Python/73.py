# 73. Set Matrix Zeroes

from __future__ import annotations

import itertools


class Solution:
    def setZeroes(self, matrix: list[list[int]]) -> None:
        m = len(matrix)
        n = len(matrix[0])
        rows, cols = set(), set()

        for i, j in itertools.product(range(m), range(n)):
            if matrix[i][j] == 0:
                rows.add(i)
                cols.add(j)

        for i, j in itertools.product(range(m), range(n)):
            if i in rows or j in cols:
                matrix[i][j] = 0
