const partition = (arr, left, right) => {
    let pivot = arr[right];
    let i = left - 1;
    for (let j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            [arr[j], arr[i]] = [arr[i], arr[j]];
        }
    }
    [arr[right], arr[i + 1]] = [arr[i + 1], arr[right]];
    return i + 1;
};

const quickSort = (arr, left, right) => {
    if (left < right) {
        let pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
};

const arr = [5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 0];
quickSort(arr, 0, arr.length - 1);

arr.forEach((item) => {
    console.log(item);
});