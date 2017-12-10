package lcode5

import (
	"testing"
)

func TestCase1(t *testing.T) {
	m, n := findLongestPalindrome("aaa", 1, 1)
	if m != 0 || n != 3 {
		t.Errorf("m=%d, n=%d", m, n)
	}

	m, n = findLongestPalindrome("addddbddddc", 5, 5)
	if m != 1 || n != 10 {
		t.Errorf("m=%d, n=%d", m, n)
	}
}

func TestCase2(t *testing.T) {
	m, n := findLongestPalindrome("abba", 1, 2)
	if m != 0 || n != 4 {
		t.Errorf("m=%d, n=%d", m, n)
	}
	m, n = findLongestPalindrome("abdaceffecadff", 6, 7)
	if m != 2 || n != 12 {
		t.Errorf("m=%d, n=%d", m, n)
	}
}

func TestCase3(t *testing.T) {
	ret := longestPalindrome("babad")
	if ret != "bab" {
		t.Errorf("ret=%s", ret)
	}
}

func TestCase4(t *testing.T) {
	ret := longestPalindrome("cbbd")
	if ret != "bb" {
		t.Errorf("ret=%s", ret)
	}
}

func TestCase5(t *testing.T) {
	ret := longestPalindrome("ccc")
	if ret != "ccc" {
		t.Errorf("ret=%s", ret)
	}
}
