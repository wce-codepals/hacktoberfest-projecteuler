package main

import "fmt"

func main() {
	var sum int
	for i := 0; i < 1000; i++ {
		if i%3 == 0 || i%5 == 0 {
			sum = sum + i
		}
	}
	fmt.Printf("Sum of multiples of 3 and 5: %v\n", sum)
}
