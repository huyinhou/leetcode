package lcode647

import "testing"

func countSubstrings(s string) int {
	total := 0
	size := len(s)
	cl, cr := 0, 0
	for i := 0; i < size; i++ {
		total += 1

		// odd
		for cl, cr = i-1, i+1; cl >= 0 && cr < size && s[cl] == s[cr]; cl, cr = cl-1, cr+1 {
			total += 1
		}

		// even
		for cl, cr = i, i+1; cl >= 0 && cr < size && s[cl] == s[cr]; cl, cr = cl-1, cr+1 {
			total += 1
		}
	}
	return total
}

func Test1(t *testing.T) {
	if 6 != countSubstrings("aaa") {
		t.Error(1)
	}
	if 3 != countSubstrings("abc") {
		t.Error(2)
	}
}
