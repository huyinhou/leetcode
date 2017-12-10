package lcode338

import (
	"fmt"
	"testing"
)

func countBits(num int) []int {
	ret := make([]int, num+1)
	ret[0] = 0
	for i := 1; i <= num; i++ {
		ret[i] = ret[i>>1] + i&1
	}
	return ret
}

func Test1(t *testing.T) {
	fmt.Println(countBits(5))
}
