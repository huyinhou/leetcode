package lcode448

import "testing"
import "fmt"

func findDisappearedNumbers(nums []int) []int {
	for _, n := range nums {
		if n < 0 {
			n = -n
		}
		if nums[n-1] > 0 {
			nums[n-1] = -nums[n-1]
		}
	}
	var ret []int
	for i, n := range nums {
		if n > 0 {
			ret = append(ret, i+1)
		}
	}
	return ret
}

func Test1(t *testing.T) {
	fmt.Println(findDisappearedNumbers([]int{1, 2, 2, 3, 4}))
	fmt.Println(findDisappearedNumbers([]int{4, 3, 2, 7, 8, 2, 3, 1}))
}
