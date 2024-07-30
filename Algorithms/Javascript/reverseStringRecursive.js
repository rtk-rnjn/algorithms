const reverseStringRecursive = (str) => {
    if (str === '') {
        return '';
    } else {
        return reverseStringRecursive(str.substr(1)) + str.charAt(0);
    }
}

console.log(reverseStringRecursive('hello')); // olleh
