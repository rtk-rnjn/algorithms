const primeNumber = (num) => {
    if (num < 2) {
        return false;
    }

    let sqrt = Math.floor(Math.sqrt(num));

    for (let i = 2; i <= sqrt; i++) {
        if (num % i === 0) {
            return false;
        }
    }

    return true;
}

console.log(primeNumber(2)); // true
console.log(primeNumber(3)); // true
console.log(primeNumber(4)); // false
console.log(primeNumber(5)); // true
