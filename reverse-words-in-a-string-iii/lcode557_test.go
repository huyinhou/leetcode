package lcode557

import (
	"bytes"
	"fmt"
	"strings"
	"testing"
)

func reverseString(s string) string {
	size := len(s)
	data := make([]byte, size)
	for i, j := size-1, 0; i >= 0; i, j = i-1, j+1 {
		data[j] = s[i]
	}
	return string(data)
}

func reverseWords(s string) string {
	buf := bytes.Buffer{}
	size := len(s)
	for i := 0; i < size; {
		j := strings.Index(s[i:], " ")
		if j < 0 {
			j = size
		} else {
			j += i
		}
		if j == i {
			buf.WriteString(" ")
			i = j + 1
		} else {
			buf.WriteString(reverseString(s[i:j]))
			i = j
		}
	}
	return buf.String()
}

func Test1(t *testing.T) {
	fmt.Println(reverseWords("Let's take    LeetCode contest"))
}
