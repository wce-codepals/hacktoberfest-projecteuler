package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
	"time"
)

func main() {

	start := time.Now()
	current := 1
	finished := false
	for finished != true {

		finished = isAnagram(current, current*2) && isAnagram(current, current*3) && isAnagram(current, current*4) && isAnagram(current, current*5) && isAnagram(current, current*6)

		if finished {
			fmt.Println(current)
		}
		current++
	}
	t := time.Now()
	elapsed := t.Sub(start)
	fmt.Println(elapsed)
}

func isAnagram(number1, number2 int) bool {
	strNumber1 := strconv.Itoa(number1)
	strNumber2 := strconv.Itoa(number2)
	number1Array := strings.Split(strNumber1, "")
	number2Array := strings.Split(strNumber2, "")
	sort.Strings(number1Array)
	sort.Strings(number2Array)

	return compare(number1Array, number2Array)
}

func compare(array1, array2 []string) bool {
	if len(array1) == len(array2) {
		for i, ind := range array1 {
			if ind != array2[i] {
				return false
			}
		}
		return true
	}
	return false
}
