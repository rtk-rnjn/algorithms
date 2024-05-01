from __future__ import annotations


def kmp_search(text: str, pattern: str) -> int:
    n, m = len(text), len(pattern)
    if m == 0:
        return 0
    lps = [0] * m
    compute_lps(pattern, m, lps)
    i, j = 0, 0
    while i < n:
        if text[i] == pattern[j]:
            i += 1
            j += 1
        if j == m:
            return i - j
        elif i < n and text[i] != pattern[j]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    return -1


def compute_lps(pattern: str, m: int, lps: list[int]) -> None:
    length, i = 0, 1
    while i < m:
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        elif length == 0:
            lps[i] = 0
            i += 1

        else:
            length = lps[length - 1]


if __name__ == "__main__":
    text = "CAABAACAADAABAABA"
    pattern = "AABA"
    index = kmp_search(text, pattern)
    if index != -1:
        print(f"Pattern found at index {index}")
    else:
        print("Pattern not found")
