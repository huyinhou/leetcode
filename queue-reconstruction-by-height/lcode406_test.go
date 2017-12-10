package lcode406

import (
	"fmt"
	"sort"
	"testing"
)

type PeopleQueue [][]int

func (p PeopleQueue) Len() int {
	return len(p)
}

func (p PeopleQueue) Less(i, j int) bool {
	pi, pj := p[i], p[j]
	if pi[0] > pj[0] {
		return true
	} else if pi[0] == pj[0] {
		return pi[1] < pj[1]
	}
	return false
}

func (p PeopleQueue) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func reconstructQueue(people [][]int) [][]int {
	sort.Sort(PeopleQueue(people))
	// fmt.Println(people)
	for i := 0; i < len(people); i++ {
		target := people[i][1]
		if target == i {
			continue
		}
		pi := people[i]
		for j := i; j > target; j-- {
			people[j] = people[j-1]
		}
		people[target] = pi
		// fmt.Println(i, people)
	}
	return people
}

func Test1(t *testing.T) {
	people := [][]int{
		[]int{7, 0},
		[]int{4, 4},
		[]int{7, 1},
		[]int{5, 0},
		[]int{6, 1},
		[]int{5, 2},
	}
	fmt.Println(reconstructQueue(people))

	people = [][]int{
		[]int{7, 0},
		[]int{7, 1},
		[]int{7, 2},
		[]int{7, 3},
		[]int{5, 0},
		[]int{4, 4},
	}
	fmt.Println(reconstructQueue(people))
}
