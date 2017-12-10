package lcode136

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret := singleNumber([]int{1, 1, 2})
	if ret != 2 {
		t.Error(1)
	}
	ret = singleNumber([]int{2, 3, 7, 2, 3})
	if ret != 7 {
		t.Error(2)
	}
	ret = singleNumber([]int{-1, -3, 7, 7, -3})
	if ret != -1 {
		t.Error(3)
	}
}
