package lcode496

import (
	"fmt"
	"testing"
)

func nextGreaterElement(findNums []int, nums []int) []int {
	stack := make([]int, 0)
	next := make(map[int]int)
	for _, v := range nums {
		for size := len(stack); size > 0 && v > stack[size-1]; size-- {
			next[stack[size-1]] = v
			stack = stack[:size-1]
		}
		stack = append(stack, v)
	}
	retval := make([]int, 0)
	for _, v := range findNums {
		if n, ok := next[v]; ok {
			retval = append(retval, n)
		} else {
			retval = append(retval, -1)
		}
	}
	return retval
}

func Test1(t *testing.T) {
	fmt.Println(nextGreaterElement([]int{4, 1, 3}, []int{1, 3, 4, 2, 5}))
}
