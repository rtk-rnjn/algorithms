const insertionSort = (arr) => {
    for (let i = 1; i < arr.length; i++) {
        const current = arr[i];
        let j = i - 1;
        while (j >= 0 && current < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
};

const arr = [5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 0];
insertionSort(arr);

arr.forEach((item) => {
    console.log(item);
});
