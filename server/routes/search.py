from __future__ import annotations

import re
import urllib.parse
from functools import lru_cache

import fuzzywuzzy
import fuzzywuzzy.fuzz
import fuzzywuzzy.process
from flask import jsonify, request
from sqlalchemy import and_, select

from server import app, db
from server.models import Code

mapper = {
    "algo": "Algorithms",
    "cp": "CP",
    "ds": "DataStructures",
}

FILENAMES: dict[str, str] = {}

VALID_LANG = ("Python", "Java", "C", "C++", "JavaScript", "CPP", "Go")
LANG_RE = re.compile(r"\b(?:py|java|c|cpp|js)\b", re.IGNORECASE)
IN_RE = re.compile(r"\b(?:algo|cp|ds)\b", re.IGNORECASE)


@lru_cache
def query_parser(query: str) -> dict[str, str]:
    query = urllib.parse.unquote(query.lower())

    lang_match = LANG_RE.search(query)
    in_match = IN_RE.search(query)

    lang = lang_match.group(0).lower() if lang_match else None
    in_ = mapper.get(in_match.group(0).lower()) if in_match else None

    cleaned_query = re.sub(LANG_RE, "", query)
    cleaned_query = re.sub(IN_RE, "", cleaned_query)

    cleaned_query = cleaned_query.replace("in:", "").replace("lang:", "").strip()

    return {"lang": lang or "", "in": in_ or "", "query": cleaned_query}


@lru_cache(maxsize=32)
def auto_complete(query: str):
    data = query_parser(query)

    codes = select(Code.filename, Code.code).where(
        and_(Code.filename.ilike(f"%.{data['lang']}%"), Code.filename.ilike(f"{data['in']}%")),
    )

    results = db.session.execute(codes).all()

    for result in results:
        filename = result.filename

        FILENAMES[filename] = result.code

    searchable = {
        filename: code
        for filename, code in FILENAMES.items()
        if filename.endswith(data["lang"]) and filename.startswith(data["in"])
    }

    return fuzzywuzzy.process.extract(data["query"], searchable, limit=5, scorer=fuzzywuzzy.fuzz.partial_token_sort_ratio)


@app.route("/auto-complete", methods=["GET"])
def auto_complete_route():
    query = request.args.get("query", "")

    results: list[tuple[str, int, str]] = auto_complete(query)  # type: ignore
    results = [(code, score, filename) for code, score, filename in results if score > 85]

    if not results:
        return [["No results found", -1, "Please contribute by adding more code snippets by opening a PR"]], 404

    return jsonify(results), 200
