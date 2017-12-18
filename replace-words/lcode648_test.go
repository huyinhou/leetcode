package lcode648

import (
	"fmt"
	"sort"
	"strings"
	"testing"
)

type DictEntry struct {
	Length int
	Roots  map[string]bool
}

type RootDict struct {
	Roots []*DictEntry
}

func (d *RootDict) Len() int {
	return len(d.Roots)
}

func (d *RootDict) Less(i, j int) bool {
	return d.Roots[i].Length < d.Roots[j].Length
}

func (d *RootDict) Swap(i, j int) {
	d.Roots[i], d.Roots[j] = d.Roots[j], d.Roots[i]
}

func (d *RootDict) FindRoot(word string) *string {
	size := len(word)
	if size == 0 {
		return nil
	}
	for i := 0; i < d.Len(); i++ {
		entry := d.Roots[i]
		prefix := entry.Length
		if prefix > size {
			return nil
		}
		// 取前缀
		key := word[0:prefix]
		if _, ok := entry.Roots[key]; ok {
			return &key
		}
	}
	return nil
}

func BuildDict(dict []string) *RootDict {
	temp := map[int]*DictEntry{}
	for _, v := range dict {
		l := len(v)
		if l == 0 {
			continue
		}
		if e, ok := temp[l]; ok {
			e.Roots[v] = true
		} else {
			temp[l] = &DictEntry{
				Length: l,
				Roots: map[string]bool{
					v: true,
				},
			}
		}
	}
	roots := make([]*DictEntry, len(temp))
	index := 0
	for k := range temp {
		roots[index] = temp[k]
		index++
	}
	ret := &RootDict{
		Roots: roots,
	}
	sort.Sort(ret)
	return ret
}

func replaceWords(dict []string, sentence string) string {
	d := BuildDict(dict)
	words := strings.Split(sentence, " ")
	for i, w := range words {
		r := d.FindRoot(w)
		if r != nil {
			words[i] = *r
		}
	}
	return strings.Join(words, " ")
}

func Test1(t *testing.T) {
	BuildDict([]string{
		"",
		"xxxx",
		"cat",
		"dat",
		"eat",
		"dddd",
	})
	dict := []string{"cat", "bat", "rat"}
	fmt.Println(replaceWords(dict, "the cattle  was rattled by the battery"))
}
