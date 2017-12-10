package lcode674

import (
	"testing"
)

func Test1(t *testing.T) {
	ret := findLengthOfLCIS([]int{1, 3, 5, 4, 7})
	if ret != 3 {
		t.Errorf("ret = %d", ret)
	}
}

func Test2(t *testing.T) {
	ret := findLengthOfLCIS([]int{2, 2, 2, 2, 2})
	if ret != 1 {
		t.Errorf("ret = %d", ret)
	}
}

func Test3(t *testing.T) {
	ret := findLengthOfLCIS([]int{})
	if ret != 0 {
		t.Errorf("ret = %d", ret)
	}
	t.Logf("ret = %d", ret)
}

func Test4(t *testing.T) {
	ret := findLengthOfLCIS([]int{1,3,5,4,2,3,4,5})
	if ret != 4 {
		t.Errorf("ret = %d", ret)
	}
}