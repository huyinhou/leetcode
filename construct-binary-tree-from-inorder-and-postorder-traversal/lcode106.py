import unittest

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        size = len(inorder)
        if size == 0:
            return None
        mid = postorder[size - 1]
        idx = 0
        for idx in range(size):
            if inorder[idx] == mid:
                break
        n = TreeNode(mid)
        n.left = self.buildTree(inorder[0:idx], postorder[0:idx])
        n.right = self.buildTree(inorder[idx + 1:], postorder[idx:size - 1])
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
        t1 = s.buildTree([2, 4, 1, 5, 3], [4, 2, 5, 3, 1])
        t2 = makeTree([1, 2, 3, 0, 4, 5])
        self.assertTrue(compTree(t1, t2))

def main():
    unittest.main()

if __name__ == '__main__':
    main()