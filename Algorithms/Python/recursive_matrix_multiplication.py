from __future__ import annotations

import itertools


def recursive_matrix_multiplication(A: list[list[int]], B: list[list[int]]) -> list[list[int]]:
    """Multiply two matrices using the recursive algorithm."""
    n = len(A)
    C = [[0] * n for _ in range(n)]
    if n == 1:
        C[0][0] = A[0][0] * B[0][0]
    else:
        C = _helper_multiplier(A, B, recursive_matrix_multiplication)
    return C


def _helper_multiplier(A, B, recursive_matrix_multiplication):
    """Based on the Strassen algorithm."""
    A11, A12, A21, A22 = split_matrix(A)
    B11, B12, B21, B22 = split_matrix(B)

    S1 = subtract_matrices(B12, B22)
    S2 = add_matrices(A11, A12)
    S3 = add_matrices(A21, A22)
    S4 = subtract_matrices(B21, B11)
    S5 = add_matrices(A11, A22)
    S6 = add_matrices(B11, B22)
    S7 = subtract_matrices(A12, A22)
    S8 = add_matrices(B21, B22)
    S9 = subtract_matrices(A11, A21)
    S10 = add_matrices(B11, B12)

    P1 = recursive_matrix_multiplication(A11, S1)
    P2 = recursive_matrix_multiplication(S2, B22)
    P3 = recursive_matrix_multiplication(S3, B11)
    P4 = recursive_matrix_multiplication(A22, S4)
    P5 = recursive_matrix_multiplication(S5, S6)
    P6 = recursive_matrix_multiplication(S7, S8)
    P7 = recursive_matrix_multiplication(S9, S10)

    C11 = add_matrices(subtract_matrices(add_matrices(P5, P4), P2), P6)
    C12 = add_matrices(P1, P2)
    C21 = add_matrices(P3, P4)
    C22 = subtract_matrices(subtract_matrices(add_matrices(P5, P1), P3), P7)
    return merge_matrices(C11, C12, C21, C22)


def split_matrix(
    A: list[list[int]],
) -> tuple[list[list[int]], list[list[int]], list[list[int]], list[list[int]]]:
    """Split a matrix into four submatrices."""
    n = len(A) // 2
    A11 = [row[:n] for row in A[:n]]
    A12 = [row[n:] for row in A[:n]]
    A21 = [row[:n] for row in A[n:]]
    A22 = [row[n:] for row in A[n:]]
    return A11, A12, A21, A22


def add_matrices(A: list[list[int]], B: list[list[int]]) -> list[list[int]]:
    """Add two matrices."""
    n = len(A)
    C = [[0] * n for _ in range(n)]
    for i, j in itertools.product(range(n), range(n)):
        C[i][j] = A[i][j] + B[i][j]
    return C


def subtract_matrices(A: list[list[int]], B: list[list[int]]) -> list[list[int]]:
    """Subtract two matrices."""
    n = len(A)
    C = [[0] * n for _ in range(n)]
    for i, j in itertools.product(range(n), range(n)):
        C[i][j] = A[i][j] - B[i][j]
    return C


def merge_matrices(A: list[list[int]], B: list[list[int]], C: list[list[int]], D: list[list[int]]) -> list[list[int]]:
    """Merge four matrices into one."""
    n = len(A)
    M = [[0] * n * 2 for _ in range(n * 2)]
    for i, j in itertools.product(range(n), range(n)):
        M[i][j] = A[i][j]
        M[i][j + n] = B[i][j]
        M[i + n][j] = C[i][j]
        M[i + n][j + n] = D[i][j]
    return M
