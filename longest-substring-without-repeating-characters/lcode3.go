package lcode3

import (
	"fmt"
)

func lengthOfLongestSubstring(s string) int {
	maxlen := 0
	size := len(s)
	if size == 0 {
		return 0
	}
	var offset [256]int
	for i := 0; i < size-maxlen; {
		j := i
		for ; (j < size) && (offset[int(s[j])] == 0); j++ {
			offset[int(s[j])] = j - i + 1
		}
		if j-i > maxlen {
			maxlen = j - i
		}
		skip := 1
		if j < size {
			skip = offset[int(s[j])]
		}
		fmt.Printf("i=%d,j=%d,maxlen=%d,skip=%d\n", i, j, maxlen, skip)
		for k := i; k < j; k++ { // restore
			offset[int(s[k])] = 0
		}
		i += skip
	}
	return maxlen
}
