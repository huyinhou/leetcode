package lcode565

import (
	"fmt"
	"testing"
)

func arrayNesting(nums []int) int {
	total := len(nums)
	retval := 0
	for i := 0; i < total; i++ {
		if nums[i] == total {
			continue
		}
		nest := []int{i}
		for j := nums[i]; j != i; j = nums[j] {
			nest = append(nest, j)
		}
		if len(nest) > retval {
			retval = len(nest)
		}
		for _, j := range nest {
			nums[j] = total
		}
	}
	return retval
}

func Test1(t *testing.T) {
	fmt.Println(arrayNesting([]int{5, 4, 0, 3, 1, 6, 2}))
}
