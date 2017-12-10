package lcode90

import (
	"fmt"
	"sort"
	"testing"
)

func subsetsWithSort(nums []int) [][]int {
	if len(nums) == 0 {
		return [][]int{[]int{}}
	}
	head := nums[0]
	same := 0
	for _, v := range nums {
		if head == v {
			same++
		} else {
			break
		}
	}

	subset := subsetsWithSort(nums[same:])
	// fmt.Printf("head=%d, same=%d, subset=%v\n", head, same, subset)
	var retval [][]int
	// fmt.Printf("nums=%v\n", nums)
	for i := 0; i <= same; i++ {
		for _, v := range subset {
			t := make([]int, i, i+len(v))
			copy(t, nums[0:i])
			// fmt.Println(i, t, nums[0:i], v)
			t = append(t, v...)
			retval = append(retval, t)
		}
	}
	// fmt.Printf("retval=%v\n", retval)
	return retval
}

func subsetsWithDup(nums []int) [][]int {
	sort.Ints(nums)
	// fmt.Println(nums)
	return subsetsWithSort(nums)
}

func TestCase1(t *testing.T) {
	ret := subsetsWithDup([]int{1, 2, 2})
	fmt.Println(ret)
	ret = subsetsWithDup([]int{1, 1, 2, 2, 2, 3, 3, 3, 3})
	fmt.Println(ret)
}
