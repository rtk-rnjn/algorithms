from __future__ import annotations

import subprocess
from functools import cache

import pygments
from pygments.lexers import get_lexer_by_name
import pygments.styles.vs
from flask import render_template
from pygments.formatters import HtmlFormatter
from pygments_ansi_color import ExtendedColorHtmlFormatterMixin, color_tokens

from server import app

COMMAND = r"git log --graph --abbrev-commit --decorate --date=relative --all --color"
FILE_PATH = f"{app.static_folder}/commits.txt"


with open(FILE_PATH, "w") as file:
    subprocess.run(COMMAND, stdout=file, shell=True, check=False)


class _HTMLFormatter(ExtendedColorHtmlFormatterMixin, HtmlFormatter):
    pass


class MyStyle(pygments.styles.vs.VisualStudioStyle):
    styles = dict(pygments.styles.vs.VisualStudioStyle.styles)
    styles.update(color_tokens(enable_256color=True))


@cache
def log_to_html(path: str = FILE_PATH) -> tuple[str, str]:
    with open(path) as file:
        output = file.read()

    formatter = _HTMLFormatter(style=MyStyle)
    lexer = get_lexer_by_name("ansi-color")
    highlighted_output = pygments.highlight(output, lexer, formatter)

    return highlighted_output, formatter.get_style_defs()


@app.route("/git-graph")
def git_graph():
    html, css = log_to_html()
    return render_template("commits.html", html=html, css=css)
