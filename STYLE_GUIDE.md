# Style Guide

This document describes the coding style used in this project. As we have so many languages, we have to define a common style for all of them.
"Yes, but why?" you may ask; the idea is to make it easier to read and understand the code, and to make it easier to maintain.

## General

### Indentation

We use spaces for indentation, and we use 4 spaces for each indentation level.

### Line length

We try to keep the line length under 80 characters, but we don't have a hard limit.

### Comments

Try not to use comments, comments can lie, but code won't. If you have to use comments, use them to explain why you did something, not what you did.
Example:

```python
def function(args: list[int]) -> str | int:
    if len(args) == 0:
        return ""

    return args[0]

data: int = function([1, 2, 3])  # type: ignore  # We know that the function returns a string, but we are testing the type checker
```

There is no need to comment the `return args[0]` line, as it is obvious what it does, but on annotation of `data: int` we need to `# type: ignore` because we are testing the type checker. Since we are `# type: ignore` we need to explain why we are doing it.

### Naming

| Language        | Type          | Naming Convention | Example       |
| --------------- | ------------- | ------------------ | ------------- |
| **Python**      | Variables     | `snake_case`       | `my_variable` |
|                 | Functions     | `snake_case`       | `my_function` |
|                 | Classes       | `PascalCase`       | `MyClass`     |
|                 | Constants     | `UPPER_SNAKE_CASE`  | `MY_CONSTANT` |
|                 | Modules       | `snake_case`       | `my_module`   |
| **C++**         | Variables     | `snake_case`       | `my_variable` |
|                 | Functions     | `snake_case`       | `my_function` |
|                 | Classes       | `PascalCase`       | `MyClass`     |
|                 | Constants     | `UPPER_SNAKE_CASE`  | `MY_CONSTANT` |
|                 | Namespaces    | `snake_case`       | `my_namespace`|
|                 | Exceptions    | `PascalCase`       | `MyException` |
| **C**           | Variables     | `snake_case`       | `my_variable` |
|                 | Functions     | `snake_case`       | `my_function` |
|                 | Constants     | `UPPER_SNAKE_CASE`  | `MY_CONSTANT` |
| **JavaScript**  | Variables     | `camelCase`        | `myVariable`  |
|                 | Functions     | `camelCase`        | `myFunction`  |
|                 | Classes       | `PascalCase`       | `MyClass`     |
|                 | Constants     | `UPPER_SNAKE_CASE`  | `MY_CONSTANT` |
|                 | Modules       | `snake_case`       | `my_module`   |
| **Java**        | Variables     | `camelCase`        | `myVariable`  |
|                 | Functions     | `camelCase`        | `myFunction`  |
|                 | Classes       | `PascalCase`       | `MyClass`     |
|                 | Constants     | `UPPER_SNAKE_CASE`  | `MY_CONSTANT` |
|                 | Packages      | `snake_case`       | `my_package`  |

### Imports

We use absolute imports, and we try to import only the needed functions/classes.

## Linting

- We use [flake8](https://flake8.pycqa.org/en/latest/) for linting in Python.
- We use [clang-format](https://clang.llvm.org/docs/ClangFormat.html) for linting in C++.
- We use [clang-format](https://clang.llvm.org/docs/ClangFormat.html) for linting in C.
- We use [eslint](https://eslint.org/) for linting in JavaScript.
- We use [checkstyle](https://checkstyle.sourceforge.io/) for linting in Java.

## Others

### C/C++

Please consider all the warnings as errors, and try to fix them. Use `-Wall -Wextra -Werror` for GCC and Clang, and `/W4 /WX` for MSVC.

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

```bash
# GCC
gcc -Wall -Wextra -Werror main.c -o main
```

```bash
# Clang
clang -Wall -Wextra -Werror main.c -o main
```

```bash
# MSVC
cl /W4 /WX main.c
```

### Style Guide for C/C++

We have `.clang-format` file and `.clang-tidy` file for C/C++.

#### Explanation for `.clang-format`

- `BasedOnStyle: LLVM`: A style that is close to LLVM's style ([LLVM Coding Standards](https://llvm.org/docs/CodingStandards.html#name-types-functions-variables-and-enumerators-properly)).

- `IndentWidth: 4`: We use 4 spaces for indentation.

- `UseTab: Never`: We use spaces for indentation.

- `BreakBeforeBraces: Allman`: We use Allman style braces, i.e. we put the opening brace on a new line.

```c
// Allman style
if (1 == 1)
{
    printf("Hello, World!\n");
}

struct node
{
    int data;
    struct node *next;
};
```

- `AlignAfterOpenBracket: Align`: We align the arguments after the opening bracket.

```c
someLongFunction(argument1,
                 argument2);
```

- `AlignOperands: true`: We align the operands, (horizontal align operands of binary and ternary expressions).

```c
int aaa = bbbbbbbbbbbbbbb +
          ccccccccccccccc;
```

- `AlignTrailingComments: true`: We align the trailing comments.

```c
int a;  // comment
int ab; // comment

int abc;  // comment
int abcd; // comment
```

- `AllowShortFunctionsOnASingleLine: false`: We don't allow short functions on a single line.

- `AllowShortIfStatementsOnASingleLine: true`: We allow short if statements on a single line.

- `AllowShortLoopsOnASingleLine: true`: We allow short loops on a single line.

- `BreakBeforeBinaryOperators: false`: We don't break before binary operators.

```c
int a = 1 + 2;
```

- `AccessModifierOffset: -4`: We use `-4` as the offset for access modifiers.

```cpp
class MyClass
{
public:
    int a;
    int b;
}
```

- `SortIncludes: false`: We don't sort the includes.

- `NamespaceIndentation: All`: We indent all the namespaces.

```cpp
namespace my_namespace
{
    int a;
    int b;
}
```

- `ColumnLimit: 120`: We try to keep the line length under 120 characters.

---

##### Explanation for `.clang-tidy`

- Checks:
  - `clang-diagnostic-*`: All the warnings from Clang.
  - `clang-analyzer-*`: All the warnings from Clang Analyzer.
  - `bugprone-*`: All the warnings from bugprone.
  - `modernize-*`: All the warnings from modernize.
  - `performance-*`: All the warnings from performance.
  - `readability-*`: All the warnings from readability.
  - `-readability-identifier-length`: We ignore the warning from readability-identifier-length.
  - `-modernize-use-trailing-return-type`: We ignore the warning from modernize-use-trailing-return-type.
  - `-readability-magic-numbers`: We ignore the warning from readability-magic-numbers.

Read Docs at [clang-tidy](https://clang.llvm.org/extra/clang-tidy/)

## Python

### Type Hints

Use annotations wherever required. Avoid using `Any` as much as possible. It would be better if you use Python 3.10 or above, as it has better type checking.

```python
from typing import TypeVar

T = TypeVar("T", bound=int | float)

def function(numbers: tuple[T, ...]) -> T:
    return numbers[0]

data: int = function((1, 2, 3))
print(data)
```

```bash
# Python 3.10
python3 main.py
```

## Java

Please Look at [CHECKSTYLE.md](CHECKSTYLE_GUIDE.md) for Java.

---

There is no tight bound to use annotations, type hints, or any other feature. You can use them as you like, but try to use them as much as possible.
The objective of this project is to learn, and maintain the readability.

Consider these codes as legacy codes, and try to improve them as much as possible.

All PRs are welcome, all issues are welcome, all suggestions are welcome. Please feel free to open an issue or a PR. No one is going to judge you.
