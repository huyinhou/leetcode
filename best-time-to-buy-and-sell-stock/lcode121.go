package lcode121

func maxProfit(prices []int) int {
	days := len(prices)
	if days <= 1 {
		return 0
	}
	for i := days - 1; i > 0; i-- {
		prices[i] = prices[i] - prices[i-1]
	}
	maxsum := 0
	premax := 0
	for i := 1; i < days; i++ {
		nowsum := prices[i]
		if premax > 0 {
			nowsum += premax
		}
		if maxsum < nowsum {
			maxsum = nowsum
		}
		premax = nowsum
	}
	return maxsum
}
