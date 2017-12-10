package lcode19

import "testing"

type ListNode struct {
	Val  int
	Next *ListNode
}

func makeList(vals []int) *ListNode {
	node := &ListNode{
		Val: 0,
	}
	head := node
	for _, val := range vals {
		head.Next = &ListNode{
			Val: val,
		}
		head = head.Next
	}
	return node.Next
}

func (l *ListNode) equalTo(r *ListNode) bool {
	for l != nil && r != nil {
		if l.Val != r.Val {
			return false
		}
		l = l.Next
		r = r.Next
	}
	return l == nil && r == nil
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	tail := head
	i := 0
	for i < n && tail != nil {
		tail = tail.Next
		i++
	}
	if tail == nil {
		if i == n {
			head = head.Next
			return head
		}
		return head
	}
	front := head
	for tail.Next != nil {
		front = front.Next
		tail = tail.Next
	}
	// fmt.Println(front)
	front.Next = front.Next.Next
	return head
}

func TestCase1(t *testing.T) {
	l1 := makeList([]int{1, 2, 3, 4})
	l2 := removeNthFromEnd(l1, 1)
	if !l2.equalTo(makeList([]int{1, 2, 3})) {
		t.Error(1)
	}
	l1 = makeList([]int{1, 2, 3, 4})
	l2 = removeNthFromEnd(l1, 2)
	if !l2.equalTo(makeList([]int{1, 2, 4})) {
		t.Error(2)
	}
	l1 = makeList([]int{1, 2, 3, 4})
	l2 = removeNthFromEnd(l1, 3)
	if !l2.equalTo(makeList([]int{1, 3, 4})) {
		t.Error(3)
	}
	l1 = makeList([]int{1, 2, 3, 4})
	l2 = removeNthFromEnd(l1, 4)
	if !l2.equalTo(makeList([]int{2, 3, 4})) {
		t.Error(4)
	}
}
