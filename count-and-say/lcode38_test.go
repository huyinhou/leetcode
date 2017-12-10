package lcode38

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret := countString("1")
	if ret != "11" {
		t.Error(ret)
	}
	ret = countString("11")
	if ret != "21" {
		t.Error(ret)
	}
	ret = countString("21")
	if ret != "1211" {
		t.Error(ret)
	}
	ret = countString("1211")
	if ret != "111221" {
		t.Error(ret)
	}
}

func TestCase2(t *testing.T) {
	ret := countAndSay(1)
	if ret != "1" {
		t.Error(ret)
	}
	ret = countAndSay(2)
	if ret != "11" {
		t.Error(ret)
	}
	ret = countAndSay(3)
	if ret != "21" {
		t.Error(ret)
	}
	ret = countAndSay(4)
	if ret != "1211" {
		t.Error(ret)
	}
	ret = countAndSay(5)
	if ret != "111221" {
		t.Error(ret)
	}
	ret = countAndSay(6)
	if ret != "312211" {
		t.Error(ret)
	}
	ret = countAndSay(7)
	if ret != "13112221" {
		t.Error(ret)
	}
	ret = countAndSay(8)
	if ret != "1113213211" {
		t.Error(ret)
	}
	ret = countAndSay(9)
	if ret != "31131211131221" {
		t.Error(ret)
	}
	ret = countAndSay(10)
	if ret != "13211311123113112211" {
		t.Error(ret)
	}
}
