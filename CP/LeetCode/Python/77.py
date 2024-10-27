from __future__ import annotations


class Solution:
    def combine(self, n: int, k: int) -> list[list[int]]:
        from itertools import combinations

        ls = []

        for i in combinations(range(1, n+1), k):
            ls.append(list(i))

        return ls

