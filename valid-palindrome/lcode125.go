package lcode125

func toLower(b byte) (byte, bool) {
	if b >= 'a' && b <= 'z' {
		return b, true
	}
	if b >= '0' && b <= '9' {
		return b, true
	}
	if b >= 'A' && b <= 'Z' {
		return b + byte(32), true
	}
	return b, false
}

func isPalindrome(s string) bool {
	size := len(s)
	if size == 0 {
		return true
	}
	i := 0
	j := size - 1
	for i <= j {
		l, ok := byte(0), false
		for i <= j {
			l, ok = toLower(s[i])
			if !ok {
				i++
			} else {
				break
			}
		}
		if !ok { // i > j
			return true
		}

		r, ok := byte(0), false
		for i <= j {
			r, ok = toLower(s[j])
			if !ok {
				j--
			} else {
				break
			}
		}
		if !ok {
			return false
		}
		if l != r {
			return false
		} else {
			i++
			j--
		}
	}
	return true
}
