package lcode671

type TreeNode struct {
	Val int
	Left *TreeNode
    Right *TreeNode
}

func findSecondMinimumValue(root *TreeNode) int {
    if root.Left == nil {
		return -1
	}
	lmin := root.Left.Val
	if lmin == root.Val {
		lmin = findSecondMinimumValue(root.Left)
	}
	rmin := root.Right.Val
	if rmin == root.Val {
		rmin = findSecondMinimumValue(root.Right)
	}
	if lmin < 0 {
		if rmin < 0 {
			return -1
		} 
		return rmin
	}
	if rmin < 0 {
		return lmin
	} else if lmin < rmin {
		return lmin
	}
	return rmin
}