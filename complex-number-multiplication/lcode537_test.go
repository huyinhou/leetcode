package lcode537

import (
	"fmt"
	"strconv"
	"strings"
	"testing"
)

func splitComplex(v string) (int, int) {
	idx := strings.Index(v, "+")
	r, _ := strconv.Atoi(v[0:idx])
	i, _ := strconv.Atoi(v[idx+1 : len(v)-1])
	return r, i
}
func complexNumberMultiply(a string, b string) string {
	r1, i1 := splitComplex(a)
	r2, i2 := splitComplex(b)
	r3 := r1*r2 - i1*i2
	i3 := r1*i2 + r2*i1
	return fmt.Sprintf("%d+%di", r3, i3)
}

func Test1(t *testing.T) {
	r := complexNumberMultiply("1+1i", "1+1i")
	if r != "0+2i" {
		t.Error(1)
	}
	r = complexNumberMultiply("1+-1i", "1+-1i")
	if r != "0+-2i" {
		t.Error(2)
	}
	// splitComplex("1+2i")
}
