package lcode122

func maxProfit(prices []int) int {
	days := len(prices)
	if days <= 1 {
		return 0
	}
	maxsum := 0
	for i := days - 1; i > 0; i-- {
		prices[i] -= prices[i-1]
		if prices[i] > 0 {
			maxsum += prices[i]
		}
	}
	return maxsum
}
