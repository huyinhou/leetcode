package lcode125

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret, ok := toLower('a')
	if ret != 'a' || !ok {
		t.Error(1)
	}
	ret, ok = toLower('A')
	if ret != 'a' || !ok {
		t.Error(ret, ok)
	}
	ret, ok = toLower('0')
	if ret != '0' || !ok {
		t.Error(3)
	}
	ret, ok = toLower(',')
	if ret != ',' || ok {
		t.Error(4)
	}
}

func TestCase2(t *testing.T) {
	ret := isPalindrome(",,,,,,")
	if !ret {
		t.Error(1)
	}
	ret = isPalindrome(",,,a")
	if !ret {
		t.Error(2)
	}
	ret = isPalindrome("a,,,")
	if !ret {
		t.Error(3)
	}
	ret = isPalindrome("  a,A,,")
	if !ret {
		t.Error(4)
	}
	ret = isPalindrome("A man, a plan, a canal: Panama")
	if !ret {
		t.Error(5)
	}
	ret = isPalindrome("race a car")
	if ret {
		t.Error(6)
	}
}
