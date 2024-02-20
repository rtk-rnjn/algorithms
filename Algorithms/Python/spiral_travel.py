from __future__ import annotations


def spiral_travel(matrix: list[list[int]]) -> list[int]:
    """Given a matrix, return all elements of the matrix in spiral order."""
    if not matrix:
        return []
    result: list[int] = []
    rows, cols = len(matrix), len(matrix[0])
    top, bottom = 0, rows - 1
    left, right = 0, cols - 1
    while top <= bottom and left <= right:
        result.extend(matrix[top][i] for i in range(left, right + 1))
        top += 1
        result.extend(matrix[i][right] for i in range(top, bottom + 1))
        right -= 1
        if top <= bottom:
            result.extend(matrix[bottom][i] for i in range(right, left - 1, -1))
            bottom -= 1
        if left <= right:
            result.extend(matrix[i][left] for i in range(bottom, top - 1, -1))
            left += 1
    return result
