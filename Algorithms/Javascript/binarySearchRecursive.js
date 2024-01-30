const binarySearch = (arr, left, right, target) => {
    if (left > right) {
        return -1;
    }

    const mid = Math.floor((left + right) / 2);

    if (arr[mid] === target) {
        return mid;
    }

    if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, right, target);
    }
};

const arr = [1, 2, 3, 4, 5, 6, 7, 8];
const target = 8;

const index = binarySearch(arr, 0, arr.length - 1, target);

if (index == -1) {
    console.log("Not found");
} else {
    console.log("Found at index: " + index);
}
