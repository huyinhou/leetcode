package lcode344

import (
	"testing"
)

func reverseString(s string) string {
	size := len(s)
	if size == 0 {
		return s
	}
	data := make([]byte, size)
	for i, j := size-1, 0; i >= 0; i, j = i-1, j+1 {
		data[j] = s[i]
	}
	return string(data)
}

func Test1(t *testing.T) {
	if "ddfc" != reverseString("cfdd") {
		t.Error(1)
	}
}
