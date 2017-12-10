package lcode70

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret := climbStairs(1)
	if ret != 1 {
		t.Error(ret)
	}
	ret = climbStairs(2)
	if ret != 2 {
		t.Error(ret)
	}
	ret = climbStairs(10)
	if ret != 89 {
		t.Error(ret)
	}
}
