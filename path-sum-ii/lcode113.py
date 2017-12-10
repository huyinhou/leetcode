import unittest

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        remain = sum - root.val
        retval = []
        if root.left is None and root.right is None:
            # print root.val, remain
            if remain == 0:
                return [[root.val,]]
            return []
        # print root, remain
        if root.left is not None:
            temp = self.pathSum(root.left, remain)
            # print temp
            for v in temp:
                t = [root.val,]
                t.extend(v)
                retval.append(t)
        if root.right is not None:
            temp = self.pathSum(root.right, remain)
            # print temp
            for v in temp:
                t = [root.val,]
                t.extend(v)
                retval.append(t)

        return retval

def makeTree(vals):
    nodes = [None]*len(vals)
    for i in range(len(vals)):
        nodes[i] = TreeNode(vals[i])
    for i in range(len(vals)):
        l = 2 * i + 1
        r = 2 * (i + 1)
        if l < len(vals):
            nodes[i].left = nodes[l]
        if r < len(vals):
            nodes[i].right =nodes[r]
    return nodes[0]

class TestSolution(unittest.TestCase):
    def test_1(self):
        t = makeTree([1, 2, 3, 0, 1, -4, 0, -3, 3, -4])
        s = Solution()
        ret = s.pathSum(t, 0)
        print ret

def main():
    unittest.main()

if __name__ == '__main__':
    main()