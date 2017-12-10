package lcode693

import (
	"fmt"
	"testing"
)

func hasAlternatingBits(n int) bool {
	mask, shift := 1, 0
	last := mask & n
	mask, shift = mask<<1, shift+1
	for ; shift < 32 && mask < n; shift, mask = shift+1, mask<<1 {
		bit := mask & n
		fmt.Println(bit, mask, last)
		if last != 0 {
			if bit != 0 {
				return false
			}
			last = 0
		} else {
			if bit == 0 {
				return false
			}
			last = 1
		}
	}
	return true
}

func Test1(t *testing.T) {
	if hasAlternatingBits(7) {
		t.Error(1)
	}
	if !hasAlternatingBits(5) {
		t.Error(2)
	}
	if hasAlternatingBits(11) {
		t.Error(2)
	}
	if !hasAlternatingBits(10) {
		t.Error(2)
	}
}
