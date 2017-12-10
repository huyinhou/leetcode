package lcode500

import (
	"fmt"
	"testing"
)

func keyRow(key byte) int {
	switch key {
	case 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p':
		return 1
	case 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P':
		return 1
	case 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l':
		return 2
	case 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L':
		return 2
	case 'z', 'x', 'c', 'v', 'b', 'n', 'm':
		return 3
	case 'Z', 'X', 'C', 'V', 'B', 'N', 'M':
		return 3
	}
	return 0
}

func sameRow(word string) bool {
	if len(word) == 0 {
		return true
	}

	r := keyRow(word[0])
	for i := 1; i < len(word); i++ {
		if r != keyRow(word[i]) {
			return false
		}
	}
	return true
}

func findWords(words []string) []string {
	ret := []string{}
	for _, s := range words {
		if sameRow(s) {
			ret = append(ret, s)
		}
	}
	return ret
}

func Test1(t *testing.T) {
	fmt.Println(findWords([]string{"Hello", "Alaska", "Dad", "Peace"}))
}
