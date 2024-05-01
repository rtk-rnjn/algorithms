from __future__ import annotations


def search_pattern(text: str, pattern: str) -> int:
    for i in range(0, len(text) - len(pattern) + 1):
        j = 0
        while j < len(pattern):
            if text[i + j] != pattern[j]:
                break
            j += 1
        if j == len(pattern):
            return i

    return -1


if __name__ == "__main__":
    text = "CAABAACAADAABAAABAA"
    pattern = "AABA"
    print("Pattern found at index", search_pattern(text, pattern))
