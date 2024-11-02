from __future__ import annotations

from typing import Generic, TypeVar

T = TypeVar("T")


class DequeException(Exception):
    pass


class Deque(Generic[T]):
    def __init__(self, size: int | None = None) -> None:
        self.size = size
        self.__deque = []

    def __str__(self) -> str:
        return str(self.__deque)

    def __len__(self) -> int:
        return len(self.__deque)

    def is_empty(self) -> bool:
        return len(self.__deque) == 0

    def is_full(self) -> bool:
        return False if self.size is None else len(self.__deque) == self.size

    def add_front(self, item: T) -> None:
        if self.is_full():
            error = "Deque is full"
            raise DequeException(error) from None

        self.__deque.insert(0, item)

    def add_rear(self, item: T) -> None:
        if self.is_full():
            error = "Deque is full"
            raise DequeException(error) from None

        self.__deque.append(item)

    def remove_front(self) -> T:
        if self.is_empty():
            error = "Deque is empty"
            raise DequeException(error) from None

        return self.__deque.pop(0)

    def remove_rear(self) -> T:
        if self.is_empty():
            error = "Deque is empty"
            raise DequeException(error) from None

        return self.__deque.pop()

    def peek_front(self) -> T:
        if self.is_empty():
            error = "Deque is empty"
            raise DequeException(error) from None

        return self.__deque[0]

    def peek_rear(self) -> T:
        if self.is_empty():
            error = "Deque is empty"
            raise DequeException(error) from None

        return self.__deque[-1]

    def clear(self) -> None:
        self.__deque.clear()


if __name__ == "__main__":
    deque = Deque[int](5)

    print("Is empty:", deque.is_empty())
    print("Is full:", deque.is_full())
    print("Deque:", deque)

    for i in range(5):
        deque.add_front(i)

    print("Is empty:", deque.is_empty())
    print("Is full:", deque.is_full())
    print("Deque:", deque)

    try:
        deque.add_front(5)
    except DequeException as e:
        print(e)
