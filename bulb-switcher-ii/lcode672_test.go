package lcode672

func flipLights(n int, m int) int {
	if m <= 0 || n <= 0 {
		return 1
	}
	if n == 1 {
		return 2
	}
	if n == 2 {
		if m == 1 {
			return 3
		}
		return 4
	}
	// n >= 3
	if m == 1 {
		return 4 // 1 2 3 4
	} else if m == 2 {
		return 7 // N 1 2 3 1+4 2+4 3+4
	}
	return 8
}
