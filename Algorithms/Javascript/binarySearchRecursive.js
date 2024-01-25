const binarySearch = (arr, left, right, target) => {
  if (left > right) {
    console.log(`Not found ${target}\n`)
    return
  }

  let mid = (left + right) / 2
  mid = Math.floor(mid)
  if (arr[mid] === target) {
    console.log(`Found ${target} at index ${mid}\n`)
  } else if (arr[mid] < target) {
    binarySearch(arr, mid + 1, right, target)
  } else {
    binarySearch(arr, left, mid - 1, target)
  }
}

const arr = [1, 2, 3, 4, 5, 6]
const len = arr.length
binarySearch(arr, 0, len - 1, 3)
binarySearch(arr, 0, len - 1, 7)
