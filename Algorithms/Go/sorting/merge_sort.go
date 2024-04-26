package main

import "fmt"

func merge(left []int, right []int) []int {
	var result []int
	l := 0
	r := 0

	for l < len(left) && r < len(right) {
		if left[l] < right[r] {
			result = append(result, left[l])
			l++
		} else {
			result = append(result, right[r])
			r++
		}
	}

	for l < len(left) {
		result = append(result, left[l])
		l++
	}

	for r < len(right) {
		result = append(result, right[r])
		r++
	}

	return result
}

func mergeSort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}

	mid := len(arr) / 2
	left := mergeSort(arr[:mid])
	right := mergeSort(arr[mid:])

	return merge(left, right)
}

func main() {
	arr := []int{5, 4, 3, 2, 1}
	fmt.Println(mergeSort(arr))
}
