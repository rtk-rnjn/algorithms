package main

import "fmt"

func binarySearch(arr []int, left int, right int, target int) int {
	if left > right {
		return -1
	}

	mid := left + (right-left)/2

	if arr[mid] == target {
		return mid
	}

	if arr[mid] > target {
		return binarySearch(arr, left, mid-1, target)
	}

	return binarySearch(arr, mid+1, right, target)
}

func main() {
	arr := []int{1, 2, 3, 4, 5}
	fmt.Println(binarySearch(arr, 0, len(arr)-1, 3))
}