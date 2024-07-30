const sumOfDigitsRecursive = (num) => {
    if (num === 0) {
        return 0;
    }

    return num % 10 + sumOfDigitsRecursive(Math.floor(num / 10));
}

console.log(sumOfDigitsRecursive(123)); // 6
