import unittest

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if t1 is None:
            return t2
        elif t2 is None:
            return t1
        node = TreeNode(t1.val + t2.val)
        node.left = self.mergeTrees(t1.left, t2.left)
        node.right = self.mergeTrees(t1.right, t2.right)
        return node

def makeTree(vals):
    size = len(vals)
    nodes = [None] * size
    for i in range(size - 1, -1, -1):
        if vals[i] == 0:
            continue
        nodes[i] = TreeNode(vals[i])
        l = 2 * i + 1
        if l < size:
            nodes[i].left = nodes[l]
        r = 2 * (i + 1)
        if r < size:
            nodes[i].right = nodes[r]
    return nodes[0]

def compTree(t1, t2):
    if t1 is None:
        return t2 is None
    if t2 is None:
        return False
    if t1.val != t2.val:
        return False
    return compTree(t1.left, t2.left) and compTree(t1.right, t2.right)

class TestSolution(unittest.TestCase):
    def test1(self):
        t1 = makeTree([1])
        t2 = makeTree([1, 2, 3])
        t3 = makeTree([2, 2, 3])
        s = Solution()
        self.assertTrue(compTree(t3, s.mergeTrees(t1, t2)))

        t1 = makeTree([1, 2, 0, 0, 4])
        t2 = makeTree([1, 2, 3, 4, 8, 9])
        t3 = makeTree([2, 4, 3, 4, 12, 9])
        self.assertTrue(compTree(t3, s.mergeTrees(t1, t2)))

def main():
    unittest.main()

if __name__ == '__main__':
    main()        