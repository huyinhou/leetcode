package lcode349

import "testing"
import "fmt"

func intersection(nums1 []int, nums2 []int) []int {
	if len(nums2) > len(nums1) {
		nums1, nums2 = nums2, nums1
	}
	valmap := map[int]int{}
	for _, v := range nums1 {
		valmap[v] = 1
	}
	retval := []int{}
	for _, v := range nums2 {
		if _, ok := valmap[v]; ok {
			retval = append(retval, v)
			delete(valmap, v)
		}
	}
	return retval
}

func Test1(t *testing.T) {
	fmt.Println(intersection([]int{1, 2, 3, 2, 3}, []int{1, 2, 3, 4}))
}
