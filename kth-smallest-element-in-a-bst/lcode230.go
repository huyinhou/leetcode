package lcode230

type TreeNode struct {
	Val int
	Left *TreeNode
    Right *TreeNode
}

/* 第二个为true，第一个值为第k个元素
  第二个为false，第一个值为该树中节点个数 */
func binarySearch(root *TreeNode, k int) (int, bool) {
	total := 0
    if root.Left != nil {
		ret, ok := binarySearch(root.Left, k)
		if ok {
			return ret, true
		}
		k -= ret
		total += ret
	}
	if k == 1 {
		return root.Val, true
	}
	k -= 1
	total += 1
	
	if root.Right != nil {
		ret, ok := binarySearch(root.Right, k)
		if ok {
			return ret, true
		}
		total += ret
	}
	return total, false
}

func kthSmallest(root *TreeNode, k int) int {
	ret, _ := binarySearch(root, k)
	return ret
}