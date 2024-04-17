from __future__ import annotations

import itertools


def matrix_multiplication(A: list[list[int]], B: list[list[int]]) -> list[list[int]]:
    """Multiply two matrices using the naive algorithm."""
    n = len(A)
    C = [[0] * n for _ in range(n)]
    for i, j, k in itertools.product(range(n), range(n), range(n)):
        C[i][j] += A[i][k] * B[k][j]
    return C
