# ALGORITHMS [![Codacy Badge](https://app.codacy.com/project/badge/Grade/9eac14aebddd4146b6b034391c7c4050)](https://app.codacy.com/gh/rtk-rnjn/algorithms/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)

## How to run?

There is nothing to run. Just for the fun purpose there exists a [`main.py`](main.py) file, which runs a web server on your local machine. You can run it by executing the following command:

```bash
python main.py
```

Make sure you have Python installed on your machine and required dependencies are installed. You can install the dependencies by running the following command:

```bash
pip install -r requirements.txt
```

---

Fuck it! You are better, you don't need Python3 or install any requirements. Use Docker like a better programmer.

```bash
docker build -t algorithms_app .
```

```bash
docker run -p 8000:8000 algorithms_app
```

## Contributing

All contributions are welcome! But please have a look at the [`STYLE_GUIDE.md`](STYLE_GUIDE.md) before contributing.
