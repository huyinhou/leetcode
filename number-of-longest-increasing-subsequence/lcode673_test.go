package lcode673

import (
	"testing"
)

func Test1(t *testing.T) {
	ret := findNumberOfLIS([]int{1,3,5,4,7})
	if ret != 2 {
		t.Errorf("ret = %d", ret)
	}
}

func Test2(t *testing.T) {
	ret := findNumberOfLIS([]int{2, 2, 2, 2, 2})
	if ret != 5 {
		t.Errorf("ret = %d", ret)
	}
}

func Test3(t *testing.T) {
	ret := findNumberOfLIS([]int{})
	if ret != 0 {
		t.Errorf("ret = %d", ret)
	}
}