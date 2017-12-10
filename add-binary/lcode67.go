package lcode67

// https://leetcode.com/problems/add-binary/description/

func getDigit(b byte) int {
	switch b {
	case '1':
		return 1
	}
	return 0
}

func addBinary(a string, b string) string {
	flag := 0
	sizea := len(a)
	sizeb := len(b)
	if sizea == 0 {
		return b
	}
	if sizeb == 0 {
		return a
	}
	last := sizea
	if last < sizeb {
		last = sizeb
	}
	last++
	ret := make([]byte, last)
	i, j, d := sizea-1, sizeb-1, 0
	for last > 0 {
		da := 0
		if i >= 0 {
			da = getDigit(a[i])
		}
		db := 0
		if j >= 0 {
			db = getDigit(b[j])
		}
		d = da + db + flag
		if d > 1 {
			d -= 2
			flag = 1
		} else {
			flag = 0
		}
		last--
		ret[last] = byte(d) + '0'
		i--
		j--
	}
	for i = 0; i < len(ret)-1; i++ {
		if ret[i] != '0' {
			break
		}
	}
	return string(ret[i:])
}
