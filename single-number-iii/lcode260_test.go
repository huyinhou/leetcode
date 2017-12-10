package lcode260

import "testing"
import "fmt"

func singleNumber(nums []int) []int {
	xor := 0
	for _, v := range nums {
		xor ^= v
	}
	mask := 1
	for xor&mask == 0 {
		mask <<= 1
	}
	v1, v2 := 0, 0
	for _, v := range nums {
		if mask&v == 0 {
			v1 ^= v
		} else {
			v2 ^= v
		}
	}
	return []int{v1, v2}
}

func Test1(t *testing.T) {
	nums := []int{1, 2, 1, 3, 2, 5}
	fmt.Println(singleNumber(nums))
}
