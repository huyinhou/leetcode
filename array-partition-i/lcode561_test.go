package lcode561

import (
	"sort"
	"testing"
)

func arrayPairSum(nums []int) int {
	sort.Ints(nums)
	sum := 0
	for i := 0; i < len(nums); i += 2 {
		sum += nums[i]
	}
	return sum
}

func Test1(t *testing.T) {
	if 4 != arrayPairSum([]int{4, 1, 3, 2}) {
		t.Error("1")
	}
}
