package lcode673

/* 动态规划
 * 记以第i个元素结尾的最长子序列长度和个数分别为len[i],cnt[i]
 * 求第i+1个元素的最长子序列
 * 遍历前i个元素，找到比该元素小的最长子序列长度最大值，然后加1
 * 同时记录计算跟此最大子序列长度相同的个数之和
 * 遍历完之后，找到所有最大子序列长度相同的个数之和即可
*/
func findNumberOfLIS(nums []int) int {
	size := len(nums)
	if size == 0 {
		return 0
	}
	len := make([]int, size)
	cnt := make([]int, size)
	len[0] = 1
	cnt[0] = 1
	for idx, elem := range nums {
		if idx == 0 {
			continue
		}
		maxlen := 0
		maxcnt := 0
		for i := 0; i < idx; i += 1 {
			if nums[i] < elem {
				if maxlen < len[i] {
					maxlen = len[i]
					maxcnt = cnt[i]
				} else if maxlen == len[i] {
					maxcnt += cnt[i]
				}
			}
		}
		len[idx] = maxlen + 1
		if maxcnt == 0 {
			cnt[idx] = 1
		} else {
			cnt[idx] = maxcnt
		}
	}
	maxlen := 0
	maxcnt := 0
	for i := 0; i < size; i += 1 {
		if maxlen < len[i] {
			maxlen = len[i]
			maxcnt = cnt[i]
		} else if maxlen == len[i] {
			maxcnt += cnt[i]
		}
	}
	return maxcnt
}