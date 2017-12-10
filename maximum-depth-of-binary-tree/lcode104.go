package lcode104

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	lmax := 0
	if root.Left != nil {
		lmax = maxDepth(root.Left)
	}
	rmax := 0
	if root.Right != nil {
		rmax = maxDepth(root.Right)
	}
	if lmax > rmax {
		return lmax + 1
	}
	return rmax + 1
}
