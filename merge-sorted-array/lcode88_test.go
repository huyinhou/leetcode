package lcode88

import (
	"testing"
)

func isEqual(nums1, nums2 []int, n int) bool {
	for i := 0; i < n; i++ {
		if nums1[i] != nums2[i] {
			return false
		}
	}
	return true
}

func TestCase1(t *testing.T) {
	nums1 := make([]int, 3, 10)
	nums2 := []int{1, 2, 3}
	merge(nums1, 0, nums2, 3)
	if !isEqual(nums1, nums2, 3) {
		t.Error(nums1)
	}
	nums1 = []int{1, 2, 3, 0, 0, 0}
	nums2 = []int{}
	merge(nums1, 3, nums2, 0)
	if !isEqual(nums1, []int{1, 2, 3}, 3) {
		t.Error(nums1)
	}
	nums1 = []int{1, 1, 2, 2, 3, 3, 0, 0, 0, 0, 0}
	nums2 = []int{1, 2, 3, 4}
	merge(nums1, 6, nums2, 4)
	if !isEqual(nums1, []int{1, 1, 1, 2, 2, 2, 3, 3, 3, 4}, 10) {
		t.Error(nums1)
	}
	nums1 = []int{4, 5, 6, 0, 0, 0}
	nums2 = []int{1, 2, 3}
	merge(nums1, 3, nums2, 3)
	if !isEqual(nums1, []int{1, 2, 3, 4, 5, 6}, 6) {
		t.Error(nums1)
	}
	nums1 = []int{1, 2, 3, 7, 8, 0, 0, 0, 0, 0}
	nums2 = []int{4, 5, 6, 7, 8}
	merge(nums1, 5, nums2, 5)
	if !isEqual(nums1, []int{1, 2, 3, 4, 5, 6, 7, 7, 8, 8}, 10) {
		t.Error(nums1)
	}
	nums1 = []int{2, 0}
	nums2 = []int{1}
	merge(nums1, 1, nums2, 1)
	if !isEqual(nums1, []int{1, 2}, 2) {
		t.Error(nums1)
	}
}

func TestCase2(t *testing.T) {

}
