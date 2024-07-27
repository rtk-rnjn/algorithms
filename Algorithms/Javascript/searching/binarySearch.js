
function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        if (arr[mid] === target) {
            console.log(`Found ${target} at index ${mid}`);
            return;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    console.log(`Not found ${target}`);
}

const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
binarySearch(arr, 10);