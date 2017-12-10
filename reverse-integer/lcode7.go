package lcode7

func reverse(x int) int {
	flag := 1
	if x < 0 {
		flag = -1
	}
	ret := 0
	num := 0
	// fmt.Printf("%v\n", reflect.TypeOf(num))
	digit := 0
	for ; x != 0; x /= 10 {
		digit = x % 10
		num = ret*10 + digit*flag
		// fmt.Printf("digit=%d,num=%d\n", digit, num)
		if num >= (1 << 31) {
			return 0
		}
		ret = num
	}
	if flag < 0 {
		return -ret
	}
	return ret
}
