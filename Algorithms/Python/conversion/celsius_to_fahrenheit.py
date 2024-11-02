from __future__ import annotations


def celsius_to_fahrenheit(celsius: float) -> float:
    return celsius * 9 / 5 + 32


if __name__ == "__main__":
    celsius = 0
    print(celsius_to_fahrenheit(celsius))  # 32.0
