package lcode3

import "testing"

func TestCase1(t *testing.T) {
	ret := lengthOfLongestSubstring("")
	if ret != 0 {
		t.Errorf("ret=%d", ret)
	}
}

func TestCase2(t *testing.T) {
	ret := lengthOfLongestSubstring("abcabcbb")
	if ret != 3 {
		t.Errorf("ret=%d", ret)
	}
}

func TestCase3(t *testing.T) {
	ret := lengthOfLongestSubstring("bbbbb")
	if ret != 1 {
		t.Errorf("ret=%d", ret)
	}
}

func TestCase4(t *testing.T) {
	ret := lengthOfLongestSubstring("abcdaefghdf")
	if ret != 8 {
		t.Errorf("ret=%d", ret)
	}
}

func TestCase5(t *testing.T) {
	ret := lengthOfLongestSubstring("pwwkew")
	if ret != 3 {
		t.Errorf("ret=%d", ret)
	}
}

func TestCase6(t *testing.T) {
	ret := lengthOfLongestSubstring("c")
	if ret != 1 {
		t.Errorf("ret=%d", ret)
	}
}
