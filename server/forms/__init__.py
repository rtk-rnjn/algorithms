from __future__ import annotations

from typing import TYPE_CHECKING

from flask_wtf import FlaskForm
from wtforms import SearchField, SubmitField


class SearchForm(FlaskForm):
    search = SearchField("Search")
    submit = SubmitField("Submit")

    if TYPE_CHECKING:
        assert search.data is not None
