package lcode492

import "testing"
import "math"
import "fmt"

func constructRectangle(area int) []int {
	a := int(math.Sqrt(float64(area)))
	for area%a != 0 {
		a--
	}
	return []int{area / a, a}
}

func Test1(t *testing.T) {
	fmt.Println(constructRectangle(12))
}
