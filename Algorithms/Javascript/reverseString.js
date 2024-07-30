const reverseString = (str) => {
    return str.split('').reverse().join('');

    // return str.split('').reduce((acc, char) => char + acc, '');
    // return str.split('').reduceRight((acc, char) => acc + char, '');

    /*
    let reversed = '';
    for (let char of str) {
        reversed = char + reversed;
    }
    return reversed;
    */
}

console.log(reverseString('hello')); // olleh
