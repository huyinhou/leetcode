package lcode53

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret := maxSubArray([]int{-2, 1, -3, 4, -1, 2, 1, -5, 4})
	if ret != 6 {
		t.Error(ret)
	}
}
