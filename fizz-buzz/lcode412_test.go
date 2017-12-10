package lcode412

import (
	"fmt"
	"strconv"
	"testing"
)

func fizzBuzz(n int) []string {
	ret := make([]string, n)
	i3 := 3
	i5 := 5
	for i := 1; i <= n; i++ {
		if i == i3 {
			if i == i5 {
				ret[i-1] = "FizzBuzz"
				i5 += 5
			} else {
				ret[i-1] = "Fizz"
			}
			i3 += 3
		} else if i == i5 {
			ret[i-1] = "Buzz"
			i5 += 5
		} else {
			ret[i-1] = strconv.Itoa(i)
		}
	}
	return ret
}

func Test1(t *testing.T) {
	fmt.Println(fizzBuzz(15))
	fmt.Println(fizzBuzz(27))
}
