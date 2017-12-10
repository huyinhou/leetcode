package lcode83

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(l *ListNode) *ListNode {
	if l == nil {
		return nil
	}
	p := l
	for p != nil {
		q := p.Next
		for q != nil && q.Val == p.Val {
			q = q.Next
		}
		p.Next = q
		p = p.Next
	}
	return l
}
