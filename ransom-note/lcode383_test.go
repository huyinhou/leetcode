package lcode383

import "testing"

func canConstruct(ransomNote string, magazine string) bool {
	counter := make([]int, 26)
	index := 0
	for _, c := range magazine {
		index = int(c - 'a')
		counter[index]++
	}
	for _, c := range ransomNote {
		index = int(c - 'a')
		counter[index]--
		if counter[index] < 0 {
			return false
		}
	}
	return true
}

func Test1(t *testing.T) {
	if canConstruct("a", "b") {
		t.Error(1)
	}
	if canConstruct("aa", "ab") {
		t.Error(2)
	}
	if !canConstruct("aa", "aab") {
		t.Error(3)
	}
	if !canConstruct("sdfwerqwer", "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz") {
		t.Error(3)
	}
}
