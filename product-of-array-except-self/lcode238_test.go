package lcode238

import (
	"fmt"
	"testing"
)

func productExceptSelf(nums []int) []int {
	size := len(nums)
	ret := make([]int, size)
	if size == 0 {
		return ret
	}
	ret[0] = 1
	for i := 1; i < size; i++ {
		ret[i] = ret[i-1] * nums[i-1]
	}
	right := 1
	for i := size - 1; i >= 0; i-- {
		ret[i] *= right
		right *= nums[i]
	}
	return ret
}

func Test1(t *testing.T) {
	fmt.Println(productExceptSelf([]int{1, 2, 3, 4}))
	fmt.Println(productExceptSelf([]int{1, 2, 1, 3, 4, 2}))
}
