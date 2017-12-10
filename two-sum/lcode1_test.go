package lcode1

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret := twoSum([]int{2, 7, 11, 15}, 9)
	if ret == nil {
		t.Error("return error")
	}
	t.Log(ret)
}

func TestCase2(t *testing.T) {
	ret := twoSum([]int{3, 4, 12, 1, 7}, 8)
	if ret == nil {
		t.Error("return error")
	}
	t.Log(ret)
}
