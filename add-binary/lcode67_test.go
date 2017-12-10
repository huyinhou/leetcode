package lcode67

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret := addBinary("11", "")
	if ret != "11" {
		t.Error(ret)
	}
	ret = addBinary("", "110")
	if ret != "110" {
		t.Error(ret)
	}
}

func TestCase2(t *testing.T) {
	ret := addBinary("10", "10")
	if ret != "100" {
		t.Error(ret)
	}
	ret = addBinary("111", "11111")
	if ret != "100110" {
		t.Error(ret)
	}
	ret = addBinary("11111", "111")
	if ret != "100110" {
		t.Error(ret)
	}
	ret = addBinary("00000", "00000")
	if ret != "0" {
		t.Error(ret)
	}
}
