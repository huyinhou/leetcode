package lcode677

import "testing"
import "fmt"

type MapSum struct {
	ValMap map[string]int
	SumMap map[string]int
}

/** Initialize your data structure here. */
func Constructor() MapSum {
	return MapSum{
		ValMap: make(map[string]int),
		SumMap: make(map[string]int),
	}
}

func (this *MapSum) Insert(key string, val int) {
	klen := len(key)
	val -= this.ValMap[key]
	for i := 1; i <= klen; i++ {
		this.SumMap[key[:i]] += val
	}
	this.ValMap[key] += val
}

func (this *MapSum) Sum(prefix string) int {
	return this.SumMap[prefix]
}

func Test1(t *testing.T) {
	m := Constructor()
	m.Insert("apple", 5)
	m.Insert("app", 3)
	fmt.Println(m)
	if 8 != m.Sum("app") {
		t.Error(1)
	}
	m.Insert("abc", -2)
	fmt.Println(m)
	if 6 != m.Sum("a") {
		t.Error(2)
	}
}
