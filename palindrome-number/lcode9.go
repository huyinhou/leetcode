package lcode9

var DigitMap = []int{
	0,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
	100000000,
	1000000000,
}

func countDigits(x int) int {
	for n := len(DigitMap) - 1; n >= 0; n-- {
		if x >= DigitMap[n] {
			return n + 1
		}
	}
	return 0
}

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	if x < 10 {
		return true
	}
	digits := countDigits(x)
	half := digits / 2
	high := x / DigitMap[digits-half]
	low := x % DigitMap[half]
	// fmt.Printf("x=%d,digit=%d,half=%d,high=%d,low=%d\n",
	// x, digits, half, high, low)
	for i := 1; i < half; i++ {
		dh := high % 10
		dl := low / DigitMap[half-i]
		if dh != dl {
			return false
		}
		high /= 10
		low %= DigitMap[half-i]
	}
	return high == low
}
