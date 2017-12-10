package lcode389

import (
	"testing"
)

func findTheDifference(s string, t string) byte {
	counter := make([]int, 26)
	for i := 0; i < len(s); i++ {
		b := s[i]
		counter[b-'a'] += 1
	}
	for i := 0; i < len(t); i++ {
		b := t[i]
		counter[b-'a'] -= 1
	}
	for i := 0; i < 26; i++ {
		if counter[i] != 0 {
			return 'a' + byte(i)
		}
	}
	return 0
}

func Test1(t *testing.T) {
	if 'e' != findTheDifference("abccd", "acbcde") {
		t.Error(1)
	}
}
