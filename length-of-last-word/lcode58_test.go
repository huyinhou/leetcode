package lcode58

import (
	"testing"
)

func TestCase1(t *testing.T) {
	ret := lengthOfLastWord("")
	if ret != 0 {
		t.Error(ret)
	}
	ret = lengthOfLastWord("abc")
	if ret != 3 {
		t.Error(ret)
	}
	ret = lengthOfLastWord("abc ")
	if ret != 3 {
		t.Error(ret)
	}
	ret = lengthOfLastWord("abc dfdf")
	if ret != 4 {
		t.Error(ret)
	}
	ret = lengthOfLastWord("  ")
	if ret != 0 {
		t.Error(ret)
	}
}
