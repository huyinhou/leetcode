package lcode9

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret := isPalindrome(0)
	if ret != true {
		t.Errorf("0 => false")
	}
	ret = isPalindrome(11)
	if ret != true {
		t.Errorf("11 => false")
	}
	ret = isPalindrome(121)
	if ret != true {
		t.Errorf("121 => false")
	}
	ret = isPalindrome(1221)
	if ret != true {
		t.Errorf("1221 => false")
	}
	ret = isPalindrome(12321)
	if ret != true {
		t.Errorf("12321 => false")
	}
	ret = isPalindrome(123321)
	if ret != true {
		t.Errorf("123321 => false")
	}
	ret = isPalindrome(1234321)
	if ret != true {
		t.Errorf("1234321 => false")
	}
	ret = isPalindrome(12344321)
	if ret != true {
		t.Errorf("12344321 => false")
	}
	ret = isPalindrome(123454321)
	if ret != true {
		t.Errorf("123454321 => false")
	}
	ret = isPalindrome(1234554321)
	if ret != true {
		t.Errorf("1234554321 => false")
	}
}

func TestCase2(t *testing.T) {
	ret := isPalindrome(12345)
	if ret != false {
		t.Errorf("12345 => true")
	}
}
