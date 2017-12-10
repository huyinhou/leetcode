package lcode35

func searchInsertWithRange(nums []int, first, last, target int) int {
	if first == last {
		return first
	}
	half := (first + last) / 2
	if target == nums[half] {
		return half
	} else if target < nums[half] {
		return searchInsertWithRange(nums, first, half, target)
	}
	return searchInsertWithRange(nums, half+1, last, target)
}

func searchInsert(nums []int, target int) int {
	return searchInsertWithRange(nums, 0, len(nums), target)
}
