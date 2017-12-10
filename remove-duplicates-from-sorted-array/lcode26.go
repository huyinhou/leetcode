package lcode26

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

func removeDuplicates(nums []int) int {
	size := len(nums)
	if size <= 1 {
		return size
	}
	i, j := 0, 0
	for j < size {
		if nums[i] == nums[j] {
			j++
		} else {
			i++
			if i < j {
				nums[i] = nums[j]
			}
		}
	}
	return i + 1
}
