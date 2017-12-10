package lcode100

// https://leetcode.com/problems/same-tree/description/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil {
		return q == nil
	}
	if q == nil {
		return false
	}
	if p.Val != q.Val {
		return false
	}
	return isSameTree(p.Left, q.Left) &&
		isSameTree(p.Right, q.Right)
}
