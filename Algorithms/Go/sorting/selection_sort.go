package main

import "fmt"

func selectionSort(arr []int) {
	for i := 0; i < len(arr)-1; i++ {
		minIndex := i

		for j := i + 1; j < len(arr); j++ {
			if arr[j] < arr[minIndex] {
				minIndex = j
			}
		}

		arr[minIndex], arr[i] = arr[i], arr[minIndex]
	}
}

func main() {
	arr := []int{5, 4, 3, 2, 1}
	selectionSort(arr)
	fmt.Println(arr)
}
