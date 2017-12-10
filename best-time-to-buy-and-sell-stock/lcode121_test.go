package lcode121

import "testing"

func TestCase1(t *testing.T) {
	ret := maxProfit([]int{7, 1, 5, 3, 6, 4})
	if ret != 5 {
		t.Error(1)
	}
	ret = maxProfit([]int{7, 6, 5, 4})
	if ret != 0 {
		t.Error(2)
	}
	ret = maxProfit([]int{1, 3, 2})
	if ret != 2 {
		t.Error(3)
	}
	ret = maxProfit([]int{1, 2, 4})
	if ret != 3 {
		t.Error(4)
	}
}
