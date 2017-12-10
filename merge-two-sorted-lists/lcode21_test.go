package lcode21

import (
	"fmt"
	"testing"
)

func buildList(vals []int) *ListNode {
	var node ListNode
	tail := &node
	for i := 0; i < len(vals); i++ {
		tail.Next = &ListNode{
			Val: vals[i],
		}
		tail = tail.Next
	}
	return node.Next
}

func listEqual(l1, l2 *ListNode) bool {
	for l1 != nil && l2 != nil {
		fmt.Printf("l1=%d, l2=%d\n", l1.Val, l2.Val)
		if l1.Val != l2.Val {
			return false
		}
		l1 = l1.Next
		l2 = l2.Next
	}
	return l1 == nil && l2 == nil
}
func TestCase1(t *testing.T) {
	l1 := buildList([]int{1, 2, 3})
	ret := mergeTwoLists(l1, nil)
	if !listEqual(l1, ret) {
		t.Error("error")
	}
	ret = mergeTwoLists(nil, l1)
	if !listEqual(l1, ret) {
		t.Error("error")
	}
}

func TestCase2(t *testing.T) {
	l1 := buildList([]int{1, 2, 3})
	l2 := buildList([]int{1, 3, 4, 5})
	exp := buildList([]int{1, 1, 2, 3, 3, 4, 5})
	ret := mergeTwoLists(l1, l2)
	if !listEqual(ret, exp) {
		t.Error("error")
	}
	l1 = buildList([]int{1, 2, 3})
	l2 = buildList([]int{1, 3, 4, 5})
	ret = mergeTwoLists(l2, l1)
	if !listEqual(ret, exp) {
		t.Error("error")
	}
}
