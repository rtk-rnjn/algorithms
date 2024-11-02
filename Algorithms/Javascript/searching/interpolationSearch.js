function interpolationSearch(array, target) {
    let low = 0;
    let high = array.length - 1;

    while (low <= high && target >= array[low] && target <= array[high]) {
        if (low === high) {
            if (array[low] === target) {
                return low;
            }
            return -1;
        }

        let pos = Math.floor(low + ((high - low) / (array[high] - array[low])) * (target - array[low]));

        if (array[pos] === target) {
            return pos;
        }

        if (array[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

const array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const target = 7;

const index = interpolationSearch(array, target);

if (index !== -1) {
    console.log(`Element found at index ${index}`);
} else {
    console.log('Element not found');
}
