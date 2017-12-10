package lcode606

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

func dumpTree(t *TreeNode, buf *bytes.Buffer) {
	buf.WriteString(strconv.Itoa(t.Val))
	if t.Left != nil || t.Right != nil {
		buf.WriteByte('(')
		if t.Left != nil {
			dumpTree(t.Left, buf)
		}
		buf.WriteByte(')')
	}
	if t.Right != nil {
		buf.WriteByte('(')
		dumpTree(t.Right, buf)
		buf.WriteByte(')')
	}
}

func tree2str(t *TreeNode) string {
	if t == nil {
		return ""
	}
	buf := new(bytes.Buffer)
	dumpTree(t, buf)
	return buf.String()
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
	tree := makeTree([]int{1, 2, 3, 4})
	fmt.Println(tree2str(tree))

	tree = makeTree([]int{1, 2, 3, 0, 4, 3, 0, 0, 0, 2})
	fmt.Println(tree2str(tree))
}
