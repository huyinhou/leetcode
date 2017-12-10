package lcode53

// https://leetcode.com/problems/maximum-subarray/description/
// 1⃣️第n个元素结尾的最大子数组和：max[n] = (max[n-1] > 0 ? max[n-1] : 0) + a[n]

func maxSubArray(nums []int) int {
	size := len(nums)
	if size == 0 {
		return 0
	}
	cursum := nums[0]
	maxsum := nums[0]
	for i := 1; i < size; i++ {
		if cursum > 0 {
			cursum += nums[i]
		} else {
			cursum = nums[i]
		}
		if maxsum < cursum {
			maxsum = cursum
		}
		// fmt.Printf("i=%d, maxsum=%d\n", i, maxsum)
	}
	return maxsum
}
