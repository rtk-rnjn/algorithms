from __future__ import annotations

import urllib.parse

import pygments
import pygments.lexers
import yarl
from flask import render_template, request
from pygments.formatters import HtmlFormatter
from sqlalchemy import select

from server import app, db
from server.forms import SearchForm
from server.models import Code
from server.utils import Tio, execute_python, parse_output

tio = Tio("", "")


def get_pythontutor_url(code: str, language: str) -> str:
    url = yarl.URL("http://pythontutor.com/") / f"iframe-embed.html#code={urllib.parse.quote(code)}"
    params = {
        "cumulative": "false",
        "py": "3" if language.endswith("py") else language,
        "curInstr": "0",
        "verticalStack": "false",
    }
    url = str(url)
    for key, value in params.items():
        url += str(url) + "&" + key + "=" + value

    return url


@app.route("/", methods=["GET", "POST"])
def index():
    search_form: SearchForm = SearchForm()
    return render_template("index.html", search_form=search_form)


@app.route("/view/<path:subpath>")
def view(subpath: str):
    smt = select(Code.code).where(Code.filename == subpath)
    result = db.session.execute(smt).first()
    if result is None:
        return "File not found", 404

    code, css = code_to_html(result.code, subpath)
    return render_template(
        "view.html",
        path=subpath,
        code=code,
        css=css,
        code_querystring=urllib.parse.quote(result.code),
        pythontutor_url=get_pythontutor_url(result.code, subpath.split(".")[-1]),
    )


def code_to_html(code: str, filename: str) -> tuple[str, str]:
    lang_tp_lex = {
        "py": pygments.lexers.Python3Lexer,
        "java": pygments.lexers.JavaLexer,
        "c": pygments.lexers.CLexer,
        "cpp": pygments.lexers.CLexer,
        "js": pygments.lexers.JavascriptLexer,
    }

    lexer = lang_tp_lex.get(filename.split(".")[-1], pygments.lexers.TextLexer)
    formatter = HtmlFormatter(style="colorful")
    return pygments.highlight(code, lexer(), formatter), formatter.get_style_defs()


@app.route("/tio/", methods=["POST"])
async def tio_route():
    path: str = request.get_json().get("path", "")

    smt = select(Code.code).where(Code.filename == path)
    result = db.session.execute(smt).first()
    if result is None:
        return "File not found", 404

    lang = path.split(".")[-1]
    code = result.code

    tio.init(lang, code)
    st: str = await tio.send()

    if lang == "py":
        return {"language": lang, "code": code, **execute_python(code)}

    return {"language": lang, "code": code, **parse_output(st)}
