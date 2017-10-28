package main

import "fmt"

func main() {
	firstTerm := 1
	secondTerm := 2
	result := 0
	for secondTerm < 4000000 {
		if secondTerm%2 == 0 {
			result += secondTerm
		}
		firstTerm, secondTerm = secondTerm, firstTerm+secondTerm
	}
	fmt.Println(result)
}
