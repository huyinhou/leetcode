package lcode111

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dlr(root *TreeNode, depth int, minheight *int) {
	if root == nil {
		return
	}
	if *minheight != 0 && depth >= *minheight {
		return
	}
	if root.Left == nil && root.Right == nil { // leaf node
		*minheight = depth
		return
	}
	if root.Left != nil {
		dlr(root.Left, depth+1, minheight)
	}
	if root.Right != nil {
		dlr(root.Right, depth+1, minheight)
	}
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	mindepth := 0
	dlr(root, 1, &mindepth)
	return mindepth
}
