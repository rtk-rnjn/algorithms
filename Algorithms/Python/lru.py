from __future__ import annotations

from collections import deque
from typing import Any, Generic, TypeVar

KT = TypeVar("KT")
VT = TypeVar("VT")


class LRU(Generic[KT, VT]):
    """Least Recently Used Cache"""

    def __init__(self, size: int) -> None:
        self.size = size
        self.cache: dict[KT, VT] = {}
        self.__queue: deque[KT] = deque(maxlen=size)

    def get(self, key: KT) -> VT | None:
        if key not in self.cache:
            return None
        self.__queue.remove(key)
        self.__queue.appendleft(key)
        return self.cache[key]

    def put(self, key: KT, value: VT) -> None:
        if key in self.cache:
            self.__queue.remove(key)
        elif len(self.cache) >= self.size:
            del self.cache[self.__queue.pop()]
        self.cache[key] = value
        self.__queue.appendleft(key)

    def __setattr__(self, __name: str, __value: Any) -> None:
        if __name == "size":
            if not isinstance(__value, int):
                msg = "size must be an integer"
                raise TypeError(msg)
            if __value <= 0:
                msg = "size must be greater than 0"
                raise ValueError(msg)
        super().__setattr__(__name, __value)

    def __delattr__(self, __name: str) -> None:
        if __name == "size":
            msg = "size cannot be deleted"
            raise AttributeError(msg)
        super().__delattr__(__name)

    def __getitem__(self, key: KT) -> VT:
        if item := self.get(key):
            return item

        raise KeyError(key)

    def __setitem__(self, key: KT, value: VT) -> None:
        self.put(key, value)

    def __delitem__(self, key: KT) -> None:
        if key not in self.cache:
            raise KeyError(key)

        del self.cache[key]
        self.__queue.remove(key)

    def __repr__(self) -> str:
        return f"<LRU cache={self.cache} queue={self.__queue}>"
