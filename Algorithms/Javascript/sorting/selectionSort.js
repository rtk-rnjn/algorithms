const selectionSort = (arr) => {
    for (let i = 0; i < arr.length; i++) {
        let minIndex = i;

        for (let j = i; j < arr.length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
    }
};

const arr = [5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 0];
selectionSort(arr);

arr.forEach((item) => {
    console.log(item);
});
