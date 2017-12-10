package lcode92

import (
	"fmt"
	"testing"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, m int, n int) *ListNode {
	if m < 1 {
		m = 1
	}
	if m >= n {
		return head
	}
	if head == nil {
		return nil
	}
	tmp := &ListNode{
		Val:  0,
		Next: head,
	}
	tail := tmp
	for i := 1; i < m; i++ {
		if tail == nil {
			break
		}
		tail = tail.Next
	}
	if tail == nil || tail.Next == nil {
		return head
	}
	pm := tail.Next
	var pn *ListNode
	for i := m; i <= n; i++ {
		if pm == nil {
			break
		}
		pm, pm.Next, pn = pm.Next, pn, pm
	}
	tail.Next.Next, tail.Next = pm, pn
	return tmp.Next
}

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
	l := buildList([]int{1, 2, 3, 4, 5})
	ret := reverseBetween(l, 2, 1)
	if l != ret {
		t.Error("1")
	}

	l = buildList([]int{1, 2, 3, 4, 5})
	ret = reverseBetween(l, 1, 1)
	if !listEqual(l, ret) {
		t.Error("2")
	}

	l = buildList([]int{1, 2, 3, 4, 5})
	e := buildList([]int{2, 1, 3, 4, 5})
	ret = reverseBetween(l, 1, 2)
	if !listEqual(e, ret) {
		t.Error("3")
	}

	l = buildList([]int{1, 2, 3, 4, 5})
	e = buildList([]int{3, 2, 1, 4, 5})
	ret = reverseBetween(l, 1, 3)
	if !listEqual(e, ret) {
		t.Error("4")
	}

	l = buildList([]int{1, 2, 3, 4, 5})
	e = buildList([]int{1, 2, 3, 4, 5})
	ret = reverseBetween(l, 5, 5)
	if !listEqual(e, ret) {
		t.Error("4")
	}

	l = buildList([]int{1, 2, 3, 4, 5})
	e = buildList([]int{1, 2, 3, 5, 4})
	ret = reverseBetween(l, 4, 5)
	if !listEqual(e, ret) {
		t.Error("4")
	}

	l = buildList([]int{1, 2, 3, 4, 5})
	e = buildList([]int{1, 2, 3, 5, 4})
	ret = reverseBetween(l, 4, 6)
	if !listEqual(e, ret) {
		t.Error("4")
	}
}
