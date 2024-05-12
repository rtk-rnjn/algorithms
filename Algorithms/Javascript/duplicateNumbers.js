const duplicateNumbers = (arr) => {
    for (let i = 0; i < arr.length; i++) {
        let count = 0;
        for (let j = 0; j < arr.length; j++) {
            if (arr[i] === arr[j]) {
                count++;
            }
        }
        if (count > 1) {
            console.log(`${arr[i]} appears ${count} times\n`);
        }
    }
};

const arr = [1, 2, 3, 4, 5, 4, 3, 2, 1, 6, 6];

duplicateNumbers(arr);
