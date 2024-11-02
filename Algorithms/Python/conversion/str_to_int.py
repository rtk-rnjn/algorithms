from __future__ import annotations

mapper = {"1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9, "0": 0}


def str_to_int(string: str) -> int:
    # return int(string)

    decimal = 0

    for char in string:
        decimal = decimal * 10 + mapper[char]

    return decimal


if __name__ == "__main__":
    string = "10"
    print(str_to_int(string))  # 10
    string = "13"
    print(str_to_int(string))  # 13
    string = "255"
    print(str_to_int(string))  # 255
    string = "2147483648"
    print(str_to_int(string))  # 9876543210
