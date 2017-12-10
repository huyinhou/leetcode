package lcode38

func countString(str string) string {
	var result []byte
	size := len(str)
	for i := 0; i < size; {
		j := i + 1
		for j < size && str[j] == str[i] {
			j++
		}
		j = j - i
		result = append(result, byte(j)+'0', str[i])
		i += j
	}
	return string(result)
}

func countAndSay(n int) string {
	if n == 1 {
		return "1"
	}
	return countString(countAndSay(n - 1))
}
