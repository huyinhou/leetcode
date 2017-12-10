package lcode1

// https://leetcode.com/problems/two-sum/discuss/

func twoSum(nums []int, target int) []int {
	size := len(nums)
	for i := 0; i < size-1; i++ {
		for j := i + 1; j < size; j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return nil
}
