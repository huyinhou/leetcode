package lcode283

import (
	"fmt"
	"testing"
)

func moveZeroes(nums []int) {
	size := len(nums)
	i := size - 1
	for i >= 0 {
		if nums[i] == 0 {
			j := i + 1
			for ; j < size; j++ {
				if nums[j] == 0 {
					break
				}
				nums[j-1] = nums[j]
			}
			nums[j-1] = 0
		}
		i--
	}
}

func Test1(t *testing.T) {
	nums := []int{0, 0, 3, 4, 5, 0, 6, 0}
	moveZeroes(nums)
	fmt.Println(nums)
}
