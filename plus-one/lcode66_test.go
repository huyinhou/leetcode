package lcode66

import (
	"testing"
)

func isEqual(l, r []int) bool {
	if len(l) != len(r) {
		return false
	}
	for i := 0; i < len(l); i++ {
		if l[i] != r[i] {
			return false
		}
	}
	return true
}

func TestCase1(t *testing.T) {
	ret := plusOne([]int{9})
	if !isEqual(ret, []int{1, 0}) {
		t.Error(ret)
	}
	ret = plusOne([]int{1, 2, 3})
	if !isEqual(ret, []int{1, 2, 4}) {
		t.Error(ret)
	}
	ret = plusOne([]int{1, 9, 9})
	if !isEqual(ret, []int{2, 0, 0}) {
		t.Error(ret)
	}
}
