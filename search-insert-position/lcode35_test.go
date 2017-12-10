package lcode35

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret := searchInsert([]int{2, 5, 7, 8}, 1)
	if ret != 0 {
		t.Error(ret)
	}
	ret = searchInsert([]int{2, 5, 7, 8}, 2)
	if ret != 0 {
		t.Error(ret)
	}
	ret = searchInsert([]int{2, 5, 7, 8}, 3)
	if ret != 1 {
		t.Error(ret)
	}
}

func TestCase2(t *testing.T) {
	ret := searchInsert([]int{}, 1)
	if ret != 0 {
		t.Error(ret)
	}
	ret = searchInsert([]int{1, 3, 5, 6}, 5)
	if ret != 2 {
		t.Error(ret)
	}
	ret = searchInsert([]int{1, 3, 5, 6}, 2)
	if ret != 1 {
		t.Error(ret)
	}
	ret = searchInsert([]int{1, 3, 5, 6}, 7)
	if ret != 4 {
		t.Error(ret)
	}
	ret = searchInsert([]int{1, 3, 5, 6}, 0)
	if ret != 0 {
		t.Error(ret)
	}
}
