package main

import "fmt"

func hanoi(n int, source string, destination string, auxiliary string) {
	if n == 1 {
		fmt.Println("Move disk 1 from rod", source, "to rod", destination)
		return
	}
	hanoi(n-1, source, auxiliary, destination)
	fmt.Println("Move disk", n, "from rod", source, "to rod", destination)
	hanoi(n-1, auxiliary, destination, source)
}

func main() {
	hanoi(3, "A", "C", "B")
}
