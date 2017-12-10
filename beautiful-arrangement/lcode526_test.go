package lcode526

import (
	"testing"
)

func deepSearch(nums []int, size int) int {
	if size > 1 {
		total := 0
		for i := size - 1; i >= 0; i-- {
			if nums[i]%size == 0 ||
				size%nums[i] == 0 {
				// fmt.Println(nums[i], i+1, size)
				if i != size-1 {
					nums[i], nums[size-1] = nums[size-1], nums[i]
				}
				total += deepSearch(nums, size-1)
				if i != size-1 {
					nums[i], nums[size-1] = nums[size-1], nums[i]
				}
			}
		}
		return total
	}
	return 1
}

func countArrangement(N int) int {
	nums := make([]int, N)
	for i := 1; i <= N; i++ {
		nums[i-1] = i
	}
	return deepSearch(nums, N)
}

func Test1(t *testing.T) {
	if 2 != countArrangement(2) {
		t.Error(1)
	}
	countArrangement(3)
	countArrangement(4)
}
