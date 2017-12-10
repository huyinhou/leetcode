package lcode674

func findLengthOfLCIS(nums []int) int {
	cnt := 0
	ret := 0
    for idx, num := range nums {
		if (idx == 0) ||
			(nums[idx - 1] < num) {
			cnt += 1
		} else {
			cnt = 1
		}
		if cnt > ret {
			ret = cnt
		}
	}
	return ret
}