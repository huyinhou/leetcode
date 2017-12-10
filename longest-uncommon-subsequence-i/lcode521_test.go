package lcode521

import "testing"

func findLUSlength(a string, b string) int {
	if a == b {
		return -1
	}

	sa, sb := len(a), len(b)
	if sa > sb {
		return sa
	}
	return sb
}

func Test1(t *testing.T) {
	if findLUSlength("ab", "ab") != -1 {
		t.Error(1)
	}
	if findLUSlength("abc", "defg") != 4 {
		t.Error(2)
	}
}
