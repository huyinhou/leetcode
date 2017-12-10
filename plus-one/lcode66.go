package lcode66

// https://leetcode.com/problems/plus-one/description/
func plusOne(digits []int) []int {
	flag := 1
	size := len(digits)
	if size == 0 {
		return []int{0}
	}
	for i := size - 1; i >= 0; i-- {
		d := digits[i] + flag
		if d > 9 {
			flag = 1
			d -= 10
		} else {
			flag = 0
		}
		digits[i] = d
	}
	if flag > 0 {
		ret := make([]int, 0, 1+size)
		ret = append(ret, flag)
		ret = append(ret, digits...)
		return ret
	}
	return digits
}
