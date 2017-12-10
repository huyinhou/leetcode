package lcode655

import (
	"bytes"
	"fmt"
	"strconv"
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func treeHeight(root *TreeNode) int {
	l, r := 0, 0
	if root.Left != nil {
		l = treeHeight(root.Left)
	}
	if root.Right != nil {
		r = treeHeight(root.Right)
	}
	if l > r {
		return l + 1
	}
	return r + 1
}

func dumpNode(root *TreeNode, row, col int, m [][]string) {
	h := len(m) - row            // 子树高度
	offset := (1 << uint(h)) - 1 // 左子树节点数
	offset += (col - 1) * (1 << uint(h+1))
	fmt.Println(h, row, col, offset)
	m[row-1][offset] = strconv.Itoa(root.Val)
	if root.Left != nil {
		dumpNode(root.Left, row+1, col*2-1, m)
	}
	if root.Right != nil {
		dumpNode(root.Right, row+1, col*2, m)
	}
}

func printTree(root *TreeNode) [][]string {
	height := treeHeight(root)
	rows, cols := height, (1<<uint(height))-1
	fmt.Println(rows, cols)
	ret := make([][]string, rows)
	for i := 0; i < rows; i++ {
		ret[i] = make([]string, cols)
	}
	dumpNode(root, 1, 1, ret)
	return ret
}

// 满二叉树中序遍历
func printMatrix(m [][]string) {
	rows, cols := len(m), 0
	if rows > 0 {
		cols = len(m[0])
	}
	temp := new(bytes.Buffer)
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if m[i][j] == "" {
				temp.WriteString("-")
			} else {
				temp.WriteString(m[i][j])
			}
			temp.WriteByte(' ')
		}
		temp.WriteByte('\n')
	}
	fmt.Println(temp.String())
}

func makeTree(vals []int) *TreeNode {
	nlen := len(vals)
	nodes := make([]*TreeNode, nlen)
	for i := 0; i < nlen; i++ {
		if vals[i] != 0 {
			nodes[i] = &TreeNode{
				Val: vals[i],
			}
		}
	}
	for i := 0; i < nlen; i++ {
		if nodes[i] == nil {
			continue
		}
		lidx := 2*i + 1
		ridx := 2 * (i + 1)
		if lidx < nlen {
			nodes[i].Left = nodes[lidx]
		}
		if ridx < nlen {
			nodes[i].Right = nodes[ridx]
		}
	}
	return nodes[0]
}

func Test1(t *testing.T) {
	tree := makeTree([]int{1, 2})
	printMatrix(printTree(tree))
	// fmt.Println(printTree(tree))
	tree = makeTree([]int{1, 2, 0, 3, 0, 0, 0, 0, 4})
	printMatrix(printTree(tree))

	tree = makeTree([]int{1, 2, 3, 0, 4})
	printMatrix(printTree(tree))

	tree = makeTree([]int{1, 2, 3, 0, 4, 0, 6, 0, 0, 0, 4, 0, 0, 3, 0})
	printMatrix(printTree(tree))

	tree = makeTree([]int{3, 1, 5, 7, 2, 4, 6, 0, 0, 0, 3})
	printMatrix(printTree(tree))
}
