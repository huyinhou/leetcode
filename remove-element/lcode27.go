package lcode27

// https://leetcode.com/problems/remove-element/description/

func removeElement(nums []int, val int) int {
	size := len(nums)
	for i := 0; i < size; {
		if nums[i] == val {
			nums[i] = nums[size-1]
			size--
		} else {
			i++
		}
	}
	if size < 1 {
		return 0
	}
	if nums[size-1] == val {
		size--
	}
	return size
}
