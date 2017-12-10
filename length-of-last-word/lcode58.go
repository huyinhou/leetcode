package lcode58

// https://leetcode.com/problems/length-of-last-word/description/

func lengthOfLastWord(s string) int {
	size := len(s)
	if size == 0 {
		return 0
	}
	i := size - 1
	for i >= 0 && s[i] == ' ' {
		i--
	}
	if i < 0 {
		return 0
	}
	tail := i + 1
	for (i >= 0) && (s[i] != ' ') {
		i--
	}
	i++ // i < 0 or s[i] == ' '
	return tail - i
}
