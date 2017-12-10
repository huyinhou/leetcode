package lcode26

import "testing"

func TestCase1(t *testing.T) {
	ret := removeDuplicates([]int{1, 1, 1, 1})
	if ret != 1 {
		t.Error(ret)
	}
}

func TestCase2(t *testing.T) {
	ret := removeDuplicates([]int{})
	if ret != 0 {
		t.Error(ret)
	}
}

func TestCase3(t *testing.T) {
	ret := removeDuplicates([]int{1})
	if ret != 1 {
		t.Error(ret)
	}
}

func TestCase4(t *testing.T) {
	ret := removeDuplicates([]int{1, 1, 2, 3, 4, 4})
	if ret != 4 {
		t.Error(ret)
	}
}
