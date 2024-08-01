from __future__ import annotations


def binary_to_decimal(binary: str) -> int:
    # return int(binary, 2)

    decimal = 0

    length = len(binary)
    for i in range(length):
        decimal += int(binary[i]) * 2 ** (length - i - 1)

    return decimal


if __name__ == "__main__":
    binary = "1010"
    print(binary_to_decimal(binary))  # 10
    binary = "1101"
    print(binary_to_decimal(binary))  # 13
    binary = "11111111"
    print(binary_to_decimal(binary))  # 255
    binary = "10000000000000000000000000000000"
    print(binary_to_decimal(binary))  # 2147483648
