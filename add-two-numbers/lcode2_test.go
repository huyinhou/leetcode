package lcode2

import (
	"fmt"
	"testing"
)

func buildList(digits []int) *ListNode {
	var head, next *ListNode
	for idx, digit := range digits {
		if idx == 0 {
			head = &ListNode{
				Val: digit,
			}
			next = head
		} else {
			next.Next = &ListNode{
				Val: digit,
			}
			next = next.Next
		}
	}
	return head
}

func checkEqual(l1, l2 *ListNode) bool {
	for (l1 != nil) && (l2 != nil) {
		if l1.Val != l2.Val {
			return false
		}
		l1 = l1.Next
		l2 = l2.Next
	}
	return l1 == nil && l2 == nil
}

func dumpList(l *ListNode) {
	for l != nil {
		fmt.Printf("%d -> ", l.Val)
		l = l.Next
	}
}
func TestCase1(t *testing.T) {
	n1 := buildList([]int{2, 4, 3})
	// dumpList(n1)
	n2 := buildList([]int{5, 6, 4})
	ret := addTwoNumbers(n1, n2)
	exp := buildList([]int{7, 0, 8})
	if !checkEqual(ret, exp) {
		dumpList(ret)
		t.Error("not equal")
	}
}

func TestCase2(t *testing.T) {
	n1 := buildList([]int{3, 9})
	// dumpList(n1)
	n2 := buildList([]int{5, 9, 4})
	ret := addTwoNumbers(n1, n2)
	exp := buildList([]int{8, 8, 5})
	if !checkEqual(ret, exp) {
		dumpList(ret)
		t.Error("not equal")
	}
}

func TestCase3(t *testing.T) {
	n1 := buildList([]int{1, 2, 3})
	// dumpList(n1)
	n2 := buildList([]int{0})
	ret := addTwoNumbers(n1, n2)
	exp := buildList([]int{1, 2, 3})
	if !checkEqual(ret, exp) {
		dumpList(ret)
		t.Error("not equal")
	}
}

func TestCase4(t *testing.T) {
	n1 := buildList([]int{6, 5})
	// dumpList(n1)
	n2 := buildList([]int{4, 4})
	ret := addTwoNumbers(n1, n2)
	exp := buildList([]int{0, 0, 1})
	if !checkEqual(ret, exp) {
		dumpList(ret)
		t.Error("not equal")
	}
}
