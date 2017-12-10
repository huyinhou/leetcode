package lcode258

import "testing"

func addDigits(num int) int {
	return 1 + (num-1)%9
}

func Test1(t *testing.T) {
	if 0 != addDigits(0) {
		t.Error(1)
	}
	if 1 != addDigits(1) {
		t.Error(2)
	}
	if 1 != addDigits(10) {
		t.Error(3)
	}
	if 9 != addDigits(900) {
		t.Error(4)
	}
}
