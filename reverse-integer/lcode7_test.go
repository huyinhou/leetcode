package lcode7

import (
	"testing"
)

func TestCase1(t *testing.T) {
	num := -2147483648
	ret := reverse(num)
	if ret != 0 {
		t.Errorf("ret=%d\n", ret)
	}
}

func TestCase2(t *testing.T) {
	num := 1234
	ret := reverse(num)
	if ret != 4321 {
		t.Errorf("ret=%d\n", ret)
	}
}

func TestCase3(t *testing.T) {
	num := -2234
	ret := reverse(num)
	if ret != -4322 {
		t.Errorf("ret=%d\n", ret)
	}
}

func TestCase4(t *testing.T) {
	num := 0
	ret := reverse(num)
	if ret != 0 {
		t.Errorf("ret=%d\n", ret)
	}
}

func TestCase5(t *testing.T) {
	ret := reverse(1563847412)
	if ret != 0 {
		t.Errorf("ret=%d\n", ret)
	}
}
