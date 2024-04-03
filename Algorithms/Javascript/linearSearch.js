const linearSearch = (arr, target) => {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === target) {
            return i;
        }
    }
    return -1;
};

const arr = [5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 0];
const target = 7;

const index = linearSearch(arr, target);

console.log(index);
