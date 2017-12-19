package lcode454

import "testing"
import "fmt"

func intMap(A []int) map[int]int {
	ret := map[int]int{}
	for _, a := range A {
		ret[a]++
	}
	return ret
}

func fourSumCount(A []int, B []int, C []int, D []int) int {
	ma := intMap(A)
	mb := intMap(B)
	mab := map[int]int{}
	for a, ca := range ma {
		for b, cb := range mb {
			mab[a+b] += ca * cb
		}
	}

	mc := intMap(C)
	md := intMap(D)
	mcd := map[int]int{}
	for c, cc := range mc {
		for d, cd := range md {
			mcd[c+d] += cc * cd
		}
	}

	if len(mab) < len(mcd) {
		mab, mcd = mcd, mab
	}
	sum := 0
	for ab, cab := range mab {
		if ccd, ok := mcd[-ab]; ok {
			sum += cab * ccd
		}
	}
	return sum
}

func Test1(t *testing.T) {
	a := []int{1, 2}
	b := []int{-2, -1}
	c := []int{-1, 2}
	d := []int{0, 2}
	fmt.Println(fourSumCount(a, b, c, d))
}
