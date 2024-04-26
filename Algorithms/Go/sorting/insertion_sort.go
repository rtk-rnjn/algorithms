package main

import "fmt"

func insertionSort(arr []int) {
	for i := 1; i < len(arr); i++ {
		j := i
		for j > 0 && arr[j-1] > arr[j] {
			arr[j-1], arr[j] = arr[j], arr[j-1]
			j--
		}
	}
}

func main() {
	arr := []int{5, 4, 3, 2, 1}
	insertionSort(arr)
	fmt.Println(arr)
}
