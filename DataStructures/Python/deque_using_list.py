from __future__ import annotations

from typing import Generic, TypeVar

T = TypeVar("T")


class DequeException(Exception):
    pass


class Deque(Generic[T]):
    def __init__(self, size: int) -> None:
        if size <= 0:
            raise ValueError("size must be a positive integer")

        self.size = size
        self.__deque: list[T | None] = [None] * size
        self.__front = 0
        self.__count = 0

    def __str__(self) -> str:
        items = [
            self.__deque[(self.__front + i) % self.size]
            for i in range(self.__count)
        ]
        return str(items)

    def __len__(self) -> int:
        return self.__count

    def is_empty(self) -> bool:
        return self.__count == 0

    def is_full(self) -> bool:
        return self.__count == self.size

    def add_front(self, item: T) -> None:
        if self.is_full():
            raise DequeException("Deque is full")

        self.__front = (self.__front - 1) % self.size
        self.__deque[self.__front] = item
        self.__count += 1

    def add_rear(self, item: T) -> None:
        if self.is_full():
            raise DequeException("Deque is full")

        rear = (self.__front + self.__count) % self.size
        self.__deque[rear] = item
        self.__count += 1

    def remove_front(self) -> T:
        if self.is_empty():
            raise DequeException("Deque is empty")

        item = self.__deque[self.__front]
        self.__deque[self.__front] = None
        self.__front = (self.__front + 1) % self.size
        self.__count -= 1

        return item  # type: ignore

    def remove_rear(self) -> T:
        if self.is_empty():
            raise DequeException("Deque is empty")

        rear = (self.__front + self.__count - 1) % self.size
        item = self.__deque[rear]
        self.__deque[rear] = None
        self.__count -= 1

        return item  # type: ignore

    def peek_front(self) -> T:
        if self.is_empty():
            raise DequeException("Deque is empty")

        return self.__deque[self.__front]  # type: ignore

    def peek_rear(self) -> T:
        if self.is_empty():
            raise DequeException("Deque is empty")

        rear = (self.__front + self.__count - 1) % self.size
        return self.__deque[rear]  # type: ignore

    def clear(self) -> None:
        self.__deque = [None] * self.size
        self.__front = 0
        self.__count = 0


if __name__ == "__main__":
    deque = Deque[int](5)

    print("Is empty:", deque.is_empty())
    print("Is full:", deque.is_full())
    print("Deque:", deque)

    for i in range(5):
        deque.add_front(i)

    print("\nAfter add_front:")
    print("Deque:", deque)
    print("Front:", deque.peek_front())
    print("Rear:", deque.peek_rear())

    print("\nRemove front:", deque.remove_front())
    print("Remove rear:", deque.remove_rear())
    print("Deque:", deque)

    deque.add_rear(10)
    deque.add_front(20)

    print("\nAfter adding 10 to rear and 20 to front:")
    print("Deque:", deque)

    try:
        deque.add_front(99)
    except DequeException as e:
        print("\nException:", e)

    while not deque.is_empty():
        print("Popped:", deque.remove_front())

    print("Deque:", deque)
