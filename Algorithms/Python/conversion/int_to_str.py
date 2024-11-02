from __future__ import annotations

mapper = {1: "1", 2: "2", 3: "3", 4: "4", 5: "5", 6: "6", 7: "7", 8: "8", 9: "9", 0: "0"}


def int_to_str(decimal: int) -> str:
    # return str(decimal)

    string = ""

    while decimal > 0:
        string = mapper[decimal % 10] + string
        decimal //= 10

    return string


if __name__ == "__main__":
    decimal = 10
    print(int_to_str(decimal))  # '10'
    decimal = 13
    print(int_to_str(decimal))  # '13'
    decimal = 255
    print(int_to_str(decimal))  # '255'
    decimal = 2147483648
    print(int_to_str(decimal))  # '2147483648'
    decimal = 0
