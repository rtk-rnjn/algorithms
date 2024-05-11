from __future__ import annotations


def rabin_karp(text: str, pattern: str) -> int:
    """
    Rabin-Karp algorithm to find the index of the pattern in the text.
    If the pattern is not in the text, return -1.
    """
    if not pattern or not text:
        return -1

    if len(pattern) > len(text):
        return -1

    base = 256
    prime = 101
    text_len = len(text)
    pattern_len = len(pattern)
    h = pow(base, pattern_len - 1, prime)
    pattern_hash = 0
    text_hash = 0

    for i in range(pattern_len):
        pattern_hash = (base * pattern_hash + ord(pattern[i])) % prime
        text_hash = (base * text_hash + ord(text[i])) % prime

    for i in range(text_len - pattern_len + 1):
        if pattern_hash == text_hash and pattern == text[i : i + pattern_len]:
            return i

        if i < text_len - pattern_len:
            text_hash = (base * (text_hash - ord(text[i]) * h) + ord(text[i + pattern_len])) % prime

            if text_hash < 0:
                text_hash += prime

    return -1

if __name__ == "__main__":
    text = "Hello, World!"
    pattern = "World"
    print(rabin_karp(text, pattern))  # 7
    print(rabin_karp(text, ""))  # -1
