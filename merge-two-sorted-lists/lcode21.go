package lcode21

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var node ListNode
	tail := &node
	for (l1 != nil) && (l2 != nil) {
		if l1.Val < l2.Val {
			tail.Next = l1
			l1 = l1.Next
		} else {
			tail.Next = l2
			l2 = l2.Next
		}
		tail = tail.Next
		tail.Next = nil
	}
	if l1 == nil {
		tail.Next = l2
	}
	if l2 == nil {
		tail.Next = l1
	}
	return node.Next
}
