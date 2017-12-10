import unittest

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder) == 0:
            return None
        v = preorder[0]
        n = TreeNode(v)
        idx = 0
        for idx in range(len(inorder)):
            if inorder[idx] == v:
                break
        n.left = self.buildTree(preorder[1:idx + 1], inorder[0:idx])
        n.right = self.buildTree(preorder[idx+1:], inorder[idx+1:])
        return n

def makeTree(vals):
    size = len(vals)
    nodes = [None]*size
    for i in range(size):
        if vals[i] == 0:
            continue
        nodes[i] = TreeNode(vals[i])
    for i in range(size):
        l = 2 * i + 1
        r = 2 * (i + 1)
        if l < size:
            nodes[i].left = nodes[l]
        if r < size:
            nodes[i].right = nodes[r]
    return nodes[0]

def compTree(t1, t2):
    if t1 is None:
        if t2 is None:
            return True
        return False
    if t2 is None:
        return False
    if t1.val != t2.val:
        return False
    return compTree(t1.left, t2.left) \
            and compTree(t1.right, t2.right)

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        t1 = makeTree([1, 2, 4, 0, 3, 0, 5])
        t2 = s.buildTree([1, 2, 3, 4, 5], [2, 3, 1, 4, 5])
        self.assertTrue(compTree(t1, t2))

        t1 = makeTree([1, 2, 5, 3, 0, 0, 6, 0, 4])
        t2 = s.buildTree([1, 2, 3, 4, 5, 6], [3, 4, 2, 1, 5, 6])
        self.assertTrue(compTree(t1, t2))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()
