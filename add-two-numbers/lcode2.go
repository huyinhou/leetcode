package lcode2

// https://leetcode.com/problems/add-two-numbers/description/

type ListNode struct {
	Val  int
	Next *ListNode
}

func add(v1, v2, c int) (int, int) {
	num := v1 + v2 + c
	if num > 9 {
		return num - 10, 1
	}
	return num, 0
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}

	num, carry := add(l1.Val, l2.Val, 0)
	head := &ListNode{
		Val: num,
	}
	next := head
	l1 = l1.Next
	l2 = l2.Next

	for (l1 != nil) || (l2 != nil) {
		v1 := 0
		if l1 != nil {
			v1 = l1.Val
			l1 = l1.Next
		}
		v2 := 0
		if l2 != nil {
			v2 = l2.Val
			l2 = l2.Next
		}
		num, carry = add(v1, v2, carry)
		// fmt.Printf("%d %d\n", num, carry)
		next.Next = &ListNode{
			Val: num,
		}
		next = next.Next
	}
	if carry != 0 {
		next.Next = &ListNode{
			Val: 1,
		}
	}
	return head
}
