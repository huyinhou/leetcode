package lcode442

import "testing"
import "fmt"

func findDuplicates(nums []int) []int {
	retval := make([]int, 0)
	for _, v := range nums {
		if v < 0 {
			v = -v
		}
		if nums[v-1] < 0 {
			retval = append(retval, v)
		} else {
			nums[v-1] = -nums[v-1]
		}
	}
	return retval
}

func Test1(t *testing.T) {
	fmt.Println(findDuplicates([]int{1, 1, 2, 3, 3, 4, 5, 4}))
}
