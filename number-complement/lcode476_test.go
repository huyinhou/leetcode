package lcode476

import (
	"testing"
)

func findComplement(num int) int {
	mask := 1 << 31
	hbit := uint32(32)
	for ; hbit > 0; hbit-- {
		// fmt.Println(num, mask)
		if num&mask != 0 {
			break
		}
		mask >>= 1
	}
	// fmt.Println(hbit)
	return (^num) & (1<<hbit - 1)
}

func Test1(t *testing.T) {
	if 2 != findComplement(5) {
		t.Error(findComplement(5))
	}
	if 0 != findComplement(1) {
		t.Error(2)
	}
}
