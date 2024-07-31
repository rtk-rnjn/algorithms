from __future__ import annotations


def search_pattern(text: str, pattern: str) -> int:
    for i in range(len(text) - len(pattern) + 1):
        j = 0
        while j < len(pattern) and text[i + j] == pattern[j]:
            j += 1
        if j == len(pattern):
            return i

    return -1


if __name__ == "__main__":
    text = "CAABAACAADAABAAABAA"
    pattern = "AABA"
    print("Pattern found at index", search_pattern(text, pattern))
