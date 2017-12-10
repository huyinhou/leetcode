package lcode5

import "fmt"

func findLongestPalindrome(s string, i, j int) (int, int) {
	size := len(s)
	for i >= 0 && j < size {
		if s[i] != s[j] {
			break
		}
		i--
		j++
	}
	return i + 1, j
}

func longestPalindrome(s string) string {
	size := len(s)
	if size == 0 {
		return ""
	}
	if size == 1 {
		return s
	}
	maxlen := 1
	first := 0
	last := 1
	for i := 0; i < size-maxlen/2; i++ {
		m, n := findLongestPalindrome(s, i, i)
		fmt.Printf("m=%d,n=%d,maxlen=%d\n", m, n, maxlen)
		if n-m > maxlen {
			first = m
			last = n
			maxlen = n - m
		}
		if i < size-1 {
			m, n = findLongestPalindrome(s, i, i+1)
			if n-m > maxlen {
				first = m
				last = n
				maxlen = n - m
			}
		}
	}
	return s[first:last]
}
