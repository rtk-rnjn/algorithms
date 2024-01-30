const merger = (left, right) => {
    let result = [];
    let leftIndex = 0;
    let rightIndex = 0;
    while (leftIndex < left.length &&
        rightIndex < right.length) {
        if (left[leftIndex] < right[rightIndex]) {
            result.push(left[leftIndex]);
            leftIndex++;
        }
        else {
            result.push(right[rightIndex]);
            rightIndex++;
        }
    }
    return result.concat(left.slice(leftIndex))
        .concat(right.slice(rightIndex));
}

const mergeSort = (arr) => {
    if (arr.length === 1) {
        return arr;
    }
    let mid = Math.floor(arr.length / 2);
    let left = arr.slice(0, mid);
    let right = arr.slice(mid);
    return merger(mergeSort(left), mergeSort(right));
};

const arr = [5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 0];

let sorted = mergeSort(arr);

sorted.forEach((item) => {
    console.log(item);
});
