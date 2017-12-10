package lcode540

import (
	"testing"
)

func singleNonDuplicate(nums []int) int {
	num := 0
	for _, n := range nums {
		num ^= n
	}
	return num
}

func Test1(t *testing.T) {
	if 2 != singleNonDuplicate([]int{1, 1, 2, 3, 3, 4, 4, 8, 8}) {
		t.Error(1)
	}
	if 10 != singleNonDuplicate([]int{3, 3, 7, 7, 10, 11, 11}) {
		t.Error(2)
	}
}
