from __future__ import annotations

from sqlalchemy import TEXT, Integer
from sqlalchemy.orm import Mapped, mapped_column

from server import db

__all__ = ("Code",)


class Code(db.Model):
    id: Mapped[int] = mapped_column(Integer, primary_key=True, autoincrement=True)
    code: Mapped[str] = mapped_column(TEXT, nullable=False)
    filename: Mapped[str] = mapped_column(TEXT, nullable=False)

    def __repr__(self) -> str:
        return f"<Code filename={self.filename!r}>"
