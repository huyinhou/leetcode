package lcode462

import (
	"fmt"
	"sort"
	"testing"
)

func quickselect(nums []int, idx, start, end int) int {
	fmt.Println(nums, idx, start, end)
	l, r, key := start, end-1, nums[(start+end)/2]
	for l <= r {
		for nums[r] > key {
			r--
		}
		for nums[l] < key {
			l++
		}
		if l >= r {
			break
		}
		nums[l], nums[r] = nums[r], nums[l]
		l++
		r--
	}
	if l > idx {
		return quickselect(nums, idx, start, l)
	}
	if l == idx && r == idx {
		return nums[l]
	}
	return quickselect(nums, idx, r+1, end)
}

func minMoves2(nums []int) int {
	mid := quickselect(nums, len(nums)/2, 0, len(nums))
	fmt.Println(mid)
	total := 0
	for _, v := range nums {
		if v > mid {
			total += v - mid
		} else {
			total += mid - v
		}
	}
	return total
}

func Test1(t *testing.T) {
	nums := []int{7, 9, 3, 3, 3, 3, 2, 1, 1, 5, 10, 22, 8}
	// fmt.Println(quickselect(nums, 7, 0, len(nums)))
	nums2 := []int{7, 9, 3, 3, 3, 3, 2, 1, 1, 5, 10, 22, 8}
	sort.Ints(nums2)
	fmt.Println(nums, nums2)
	for i := 0; i < len(nums); i++ {
		// fmt.Println(nums)
		fmt.Println("i=", i)
		if quickselect(nums, i, 0, len(nums)) != nums2[i] {
			t.Error(i, 1)
		}
	}
	fmt.Println(quickselect([]int{3, 1, 2}, 1, 0, 3))
	fmt.Println(quickselect([]int{203125577, -349566234, 230332704, 48321315, 66379082, 386516853, 50986744, -250908656, -425653504, -212123143}, 5, 0, 10))
	if 2 != minMoves2([]int{1, 2, 3}) {
		t.Error(2)
	}
	if 2 != minMoves2([]int{3, 1, 2}) {
		t.Error(2)
	}
	ret := minMoves2([]int{203125577, -349566234, 230332704, 48321315, 66379082, 386516853, 50986744, -250908656, -425653504, -212123143})
	if 2127271182 != ret {
		t.Error(ret)
	}
}
