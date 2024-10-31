from __future__ import annotations

import html
import io
import resource
import sys
import time
import zlib
from functools import partial

import aiohttp

to_bytes = partial(bytes, encoding="utf-8")


def _split_with_limit(text: str, limit: int = 5) -> list[str]:
    lines: list[str] = text.splitlines()
    return lines[-limit:] + ["\n".join(lines[:-limit])] if lines else []


def _parse_split_text_tio(texts: list[str]) -> dict:
    real_time: float = float(texts[0].split(":")[1][:-1])
    user_time: float = float(texts[1].split(":")[1][:-1])
    sys_time: float = float(texts[2].split(":")[1][:-1])
    cpu_share: float = float(texts[3].split(":")[1][:-1])
    exit_code: int = int(texts[4].split(":")[1])

    output: str = texts[-1]

    return {
        "real_time": real_time,
        "user_time": user_time,
        "sys_time": sys_time,
        "cpu_share": cpu_share,
        "exit_code": exit_code,
        "output": output,
    }


def parse_output(text: str) -> dict[str, str]:
    texts = _split_with_limit(text)
    return _parse_split_text_tio(texts)


def _to_tio_string(couple):
    name, obj = couple[0], couple[1]
    if not obj:
        return b""
    if isinstance(obj, list):
        content = [f"V{name}", str(len(obj))] + obj
        return to_bytes("\x00".join(content) + "\x00")
    return to_bytes(f"F{name}\x00{len(to_bytes(obj))}\x00{obj}\x00")


class Tio:
    cache: dict = {}
    language_mapper = {
        "py": "python38pr",
        "java": "java",
        "c": "c",
        "cpp": "cpp",
        "js": "nodejs",
        "c++": "cpp",
    }

    def __init__(
        self,
        language: str,
        code: str,
        inputs="",
        compiler_flags=None,
        command_line_options=None,
        args=None,
    ) -> None:
        compiler_flags = compiler_flags or []
        command_line_options = command_line_options or []
        args = args or []
        self.backend = "https://tio.run/cgi-bin/run/api/"
        self.json = "https://tio.run/languages.json"
        self.session = None

        self.init(
            language or "py",
            code,
            inputs=inputs,
            compiler_flags=compiler_flags,
            command_line_options=command_line_options,
            args=args,
        )

    def init(self, language: str, code: str, inputs="", compiler_flags=None, command_line_options=None, args=None):
        language = self.language_mapper.get(language, None)  # type: ignore
        if not language:
            msg = "Invalid language"
            raise ValueError(msg)

        strings = {
            "lang": [language],
            ".code.tio": code,
            ".input.tio": inputs,
            "TIO_CFLAGS": compiler_flags,
            "TIO_OPTIONS": command_line_options,
            "args": args,
        }
        self.__string = strings

        bytes_ = (
            b"".join(
                map(_to_tio_string, zip(strings.keys(), strings.values(), strict=False)),
            )
            + b"R"
        )

        self.request = zlib.compress(bytes_, 9)[2:-4]

    async def send(self):
        if (self.__string["lang"][0], self.__string[".code.tio"]) in Tio.cache:
            return Tio.cache[(self.__string["lang"][0], self.__string[".code.tio"])]

        if not self.session:
            self.session = aiohttp.ClientSession()

        async with self.session as client_session:
            res = await client_session.post(self.backend, data=self.request)
            if res.status != 200:
                raise aiohttp.ClientError(res.status)

            buffer_data = await res.read()
            data: str = buffer_data.decode("utf-8")
            data = data.replace(data[:16], "")

            Tio.cache[(self.__string["lang"][0], self.__string[".code.tio"])] = data

            return data


def execute_python(code_string: str) -> dict:
    code_string = html.unescape(code_string)

    old_stdout = sys.stdout
    old_stderr = sys.stderr

    sys.stdout = io.StringIO()
    sys.stderr = io.StringIO()

    result = {
        "output": "",
        "stderr": "",
        "exit_code": 0,
        "cpu_share": 0,
        "real_time": 0,
        "user_time": 0,
        "sys_time": 0,
    }

    real_start = time.time()
    start_resources = resource.getrusage(resource.RUSAGE_SELF)
    try:
        compiled = compile(code_string, "<string>", "exec")
        eval(compiled, {"__name__": "__main__"})
    except Exception as e:
        print(e)
        result["stderr"] = str(e)
        result["exit_code"] = 1

    end_resources = resource.getrusage(resource.RUSAGE_SELF)
    real_end = time.time()

    result["output"] = sys.stdout.getvalue()

    result["user_time"] = round(end_resources.ru_utime - start_resources.ru_utime, 3)
    result["sys_time"] = round(end_resources.ru_stime - start_resources.ru_stime, 3)
    result["cpu_share"] = round(end_resources.ru_utime + end_resources.ru_stime, 2)
    result["real_time"] = round(real_end - real_start, 2)

    result["stderr"] = result["stderr"] + sys.stderr.getvalue()

    sys.stdout = old_stdout
    sys.stderr = old_stderr

    return result
