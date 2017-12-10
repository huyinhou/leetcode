package lcode14

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret := longestCommonPrefix([]string{})
	if ret != "" {
		t.Error("null strs error")
	}

	ret = longestCommonPrefix([]string{"aaa"})
	if ret != "aaa" {
		t.Error("single error")
	}

	ret = longestCommonPrefix([]string{"abc", "a"})
	if ret != "a" {
		t.Error(ret)
	}

	ret = longestCommonPrefix([]string{"a", "abc", "ddd"})
	if ret != "" {
		t.Error(ret)
	}
}
