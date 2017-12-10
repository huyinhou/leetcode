package lcode485

import "testing"

func findMaxConsecutiveOnes(nums []int) int {
	tmp, max := 0, 0
	for _, v := range nums {
		if v == 0 {
			if tmp > max {
				max = tmp
			}
			tmp = 0
		} else {
			tmp += 1
		}
	}
	if tmp > max {
		max = tmp
	}
	return max
}

func Test1(t *testing.T) {
	if 3 != findMaxConsecutiveOnes([]int{1, 1, 0, 0, 1, 1, 1}) {
		t.Error(1)
	}
}
