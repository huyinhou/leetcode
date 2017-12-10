package lcode520

import "testing"

func isUpper(c rune) bool {
	return c >= 'A' && c <= 'Z'
}

func detectCapitalUse(word string) bool {
	flag := 0
	for _, c := range word {
		if flag == 0 {
			if isUpper(c) {
				flag = 1
			} else {
				flag = -1
			}
		} else {
			if isUpper(c) {
				if flag < 0 {
					return false
				}
				flag += 1
			} else {
				if flag > 1 {
					return false
				} else if flag == 1 {
					flag = -1
				} else {
					flag -= 1
				}
			}
		}
	}
	return true
}

func Test1(t *testing.T) {
	if !detectCapitalUse("A") {
		t.Error(1)
	}
	if !detectCapitalUse("Ab") {
		t.Error(2)
	}
	if detectCapitalUse("AbC") {
		t.Error(2)
	}
	if detectCapitalUse("bbC") {
		t.Error(2)
	}
	if !detectCapitalUse("b") {
		t.Error(2)
	}
	if !detectCapitalUse("bcc") {
		t.Error(2)
	}
}
