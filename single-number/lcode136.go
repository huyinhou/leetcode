package lcode136

func singleNumber(nums []int) int {
	ret := 0
	for i := 0; i < len(nums); i++ {
		ret ^= nums[i]
	}
	return ret
}
