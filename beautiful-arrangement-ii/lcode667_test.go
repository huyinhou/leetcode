package lcode667

import (
	"fmt"
	"testing"
)

func constructArray(n int, k int) []int {
	ret := make([]int, 0, n)
	for l, r := 1, k+1; l <= r; l, r = l+1, r-1 {
		ret = append(ret, l)
		if l < r {
			ret = append(ret, r)
		}
	}
	for i := k + 2; i <= n; i++ {
		ret = append(ret, i)
	}
	return ret
}

func Test1(t *testing.T) {
	fmt.Println(constructArray(4, 2))
}
