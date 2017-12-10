package lcode27

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret := removeElement([]int{1, 2}, 2)
	if ret != 1 {
		t.Error(ret)
	}
	ret = removeElement([]int{1, 2, 3, 4, 2, 2, 1}, 2)
	if ret != 4 {
		t.Error(ret)
	}
	ret = removeElement([]int{1}, 1)
	if ret != 0 {
		t.Error(ret)
	}
	ret = removeElement([]int{1, 2, 3}, 1)
	if ret != 2 {
		t.Error(ret)
	}
}
