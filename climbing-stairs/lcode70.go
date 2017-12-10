package lcode70

import (
	"fmt"
)

/*
n 奇数
c(1+n/2, 1) +
c(2+n/2, 3) +
...
c(n, n)
n偶数
c(n/2, 0) +
c(1+n/2, 2) +
...
c(n,n)
*/

func climbStairs(n int) int {
	b := 0
	if n&1 != 0 {
		b = 1
	}
	half := n / 2
	steps := make([]int, 0, half+1)
	for a := b + half; a <= n; a, b = a+1, b+2 {
		if b == 0 {
			steps = append(steps, 1)
		} else if b == 1 {
			steps = append(steps, a)
		} else {
			steps = append(steps, a*(a-b+1)*steps[len(steps)-1]/b/(b-1))
		}
		fmt.Printf("a=%d, b=%d, steps=%d\n", a, b, steps[len(steps)-1])
	}
	total := 0
	for i := 0; i < len(steps); i++ {
		total += steps[i]
	}
	return total
}
