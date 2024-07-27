from __future__ import annotations


def hanoi_tower(n: int, source: str, target: str, auxiliary: str) -> None:
    if n == 1:
        print(f"Move disk 1 from {source} to {target}")
        return

    hanoi_tower(n - 1, source, auxiliary, target)
    print(f"Move disk {n} from {source} to {target}")
    hanoi_tower(n - 1, auxiliary, target, source)


if __name__ == "__main__":
    hanoi_tower(3, "A", "C", "B")
    # Move disk 1 from A to C
    # Move disk 2 from A to B
    # Move disk 1 from C to B
    # Move disk 3 from A to C
    # Move disk 1 from B to A
    # Move disk 2 from B to C
    # Move disk 1 from A to C
