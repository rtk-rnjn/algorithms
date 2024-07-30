const sumOfDigits = (number) => {
    if (number === 0) {
        return 0;
    }

    let result = 0;
    let num = number;

    while (num > 0) {
        result += num % 10;
        num = Math.floor(num / 10);
    }

    return result;
}

console.log(sumOfDigits(123)); // 6
