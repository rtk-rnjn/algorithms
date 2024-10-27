from __future__ import annotations


def fahrenheit_to_celsius(fahrenheit: float) -> float:
    return (fahrenheit - 32) * 5 / 9


if __name__ == "__main__":
    fahrenheit = 32
    print(fahrenheit_to_celsius(fahrenheit))  # 0.0
