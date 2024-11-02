# 6. Zigzag Conversion

from __future__ import annotations


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        rows = [""] * min(numRows, len(s))
        row = 0
        down = False
        for c in s:
            rows[row] += c
            if row in [0, numRows - 1]:
                down = not down
            row += 1 if down else -1
        return "".join(rows)
