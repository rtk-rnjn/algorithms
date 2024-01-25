const bubbleSort = (arr) => {
  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length - i; j++) {
      if (arr[j] > arr[j + 1]) {
        [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]]
      }
    }
  }
}

const arr = [5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 0]
bubbleSort(arr)
for (let i = 0; i < arr.length; i++) {
  console.log(arr[i])
}
