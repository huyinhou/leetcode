package lcode725

import "testing"
import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func splitListToParts(root *ListNode, k int) []*ListNode {
	if k == 1 {
		return []*ListNode{root}
	}
	total := 0
	start := root
	for start != nil {
		total++
		start = start.Next
	}
	average, remain := total/k, total%k
	retval := make([]*ListNode, k)
	start = root
	for i := 0; i < k; i++ {
		partlen := average
		if remain > 0 {
			partlen++
			remain--
		}
		if partlen == 0 {
			retval[i] = nil
		} else {
			tail := start
			for ; partlen > 1; partlen-- {
				tail = tail.Next
			}
			retval[i] = start
			if tail != nil {
				start = tail.Next
				tail.Next = nil
			} else {
				start = nil
			}
		}
	}
	return retval
}

func makeList(vals []int) *ListNode {
	head := ListNode{}
	tail := &head
	for _, v := range vals {
		tail.Next = &ListNode{
			Val: v,
		}
		tail = tail.Next
	}
	return head.Next
}

func dumpList(root *ListNode) []int {
	retval := []int{}
	for root != nil {
		retval = append(retval, root.Val)
		root = root.Next
	}
	return retval
}
func Test1(t *testing.T) {
	nodes := splitListToParts(makeList([]int{1, 2, 3, 4, 5}), 8)
	for _, n := range nodes {
		fmt.Println(dumpList(n))
	}
	fmt.Println()

	nodes = splitListToParts(makeList([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}), 3)
	for _, n := range nodes {
		fmt.Println(dumpList(n))
	}
	fmt.Println()

	nodes = splitListToParts(makeList([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}), 3)
	for _, n := range nodes {
		fmt.Println(dumpList(n))
	}
	fmt.Println()

	nodes = splitListToParts(makeList([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}), 3)
	for _, n := range nodes {
		fmt.Println(dumpList(n))
	}
	fmt.Println()

	nodes = splitListToParts(nil, 3)
	for _, n := range nodes {
		fmt.Println(dumpList(n))
	}
	fmt.Println()
}
