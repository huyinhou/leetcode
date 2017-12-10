package lcode14

func longestCommonPrefix(strs []string) string {
	count := len(strs)
	if count == 0 {
		return ""
	}
	if count == 1 {
		return strs[0]
	}

	minsize := len(strs[0])
	for i := 1; i < count; i++ {
		if minsize > len(strs[i]) {
			minsize = len(strs[i])
		}
	}
	i := 0
	for ; i < minsize; i++ {
		b := strs[0][i]
		j := 1
		for ; j < count; j++ {
			if b != strs[j][i] {
				break
			}
		}
		if j != count {
			break
		}
	}
	if i == 0 {
		return ""
	}
	return strs[0][0:i]
}
