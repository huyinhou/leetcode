package lcode110

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func checkBalance(root *TreeNode, depth *int) bool {
	left := 0
	if root.Left != nil {
		if !checkBalance(root.Left, &left) {
			return false
		}
	}
	right := 0
	if root.Right != nil {
		if !checkBalance(root.Right, &right) {
			return false
		}
	}
	temp := left - right
	if temp > 1 || temp < -1 {
		return false
	}
	if left > right {
		*depth = left + 1
	} else {
		*depth = right + 1
	}
	return true
}

func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	height := 0
	return checkBalance(root, &height)
}
