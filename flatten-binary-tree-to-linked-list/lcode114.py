import unittest

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def flattenEx(self, root):
        ltail = None
        if root.left is not None:
            ltail = self.flattenEx(root.left)
        rtail = None
        if root.right is not None:
            rtail = self.flattenEx(root.right)
        if ltail is not None:
            ltail.right = root.right
            root.right = root.left
            root.left = None
        if rtail is not None:
            return rtail
        if ltail is None:
            return root
        return ltail

    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        if root is None:
            return

        self.flattenEx(root)

def makeTree(vals):
    nodes = [None]*len(vals)
    for i in range(len(vals)):
        if vals[i] == 0:
            continue
        nodes[i] = TreeNode(vals[i])
    for i in range(len(vals)):
        if nodes[i] is None:
            continue
        l = 2 * i + 1
        r = 2 * (i + 1)
        if l < len(vals):
            nodes[i].left = nodes[l]
        if r < len(vals):
            nodes[i].right =nodes[r]
    return nodes[0]

class TestSolution(unittest.TestCase):
    def test_1(self):
        t = makeTree([1, 2, 3, 0, 4, 5, 6])
        s = Solution()
        s.flatten(t)
        while t is not None:
            print t.val
            self.assertTrue(t.left is None)
            t = t.right

def main():
    unittest.main()

if __name__ == '__main__':
    main()