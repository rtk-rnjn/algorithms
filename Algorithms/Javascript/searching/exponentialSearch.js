function exponentialSearch(array, target) {
    if (array[0] === target) {
        return 0;
    }

    let i = 1;

    while (i < array.length && array[i] <= target) {
        i *= 2;
    }

    let low = i / 2;
    let high = i < array.length ? i : array.length - 1;

    // Binary search

    while (low <= high) {
        let mid = low + Math.floor((high - low) / 2);

        if (array[mid] === target) {
            return mid;
        }

        if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

const array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const target = 7;

const index = exponentialSearch(array, target);

if (index !== -1) {
    console.log(`Element found at index ${index}`);
} else {
    console.log('Element not found');
}
