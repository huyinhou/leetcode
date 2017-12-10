package lcode20

// https://leetcode.com/problems/valid-parentheses/description/
func hashParentheses(b byte) int {
	switch b {
	case '{':
		return 1
	case '}':
		return -1
	case '[':
		return 2
	case ']':
		return -2
	case '(':
		return 3
	case ')':
		return -3
	}
	return 0
}

func isValid(s string) bool {
	size := len(s)
	var parentheses []int
	count := 0
	for i := 0; i < size; i++ {
		hash := hashParentheses(s[i])
		if hash == 0 {
			continue
		}
		if hash > 0 {
			parentheses = append(parentheses, hash)
			count++
		} else {
			if count > 0 {
				if hash+parentheses[count-1] == 0 {
					parentheses = parentheses[0 : count-1]
					count--
					continue
				}
			}
			return false
		}
	}
	return count == 0
}
