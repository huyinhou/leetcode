package lcode122

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret := maxProfit([]int{1, 2, 3})
	if ret != 2 {
		t.Error(1)
	}
	ret = maxProfit([]int{1, 5, 2, 7, 3})
	if ret != 9 {
		t.Error(2)
	}
}
