import unittest

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) == 0:
            return None

        stack = []
        for v in nums:
            n = TreeNode(v)
            while len(stack) > 0:
                if stack[-1].val < v:
                    n.left = stack[-1]
                    stack.pop()
                else:
                    stack[-1].right = n
                    break
            stack.append(n)
        return stack[0]

class TestSolution(unittest.TestCase):
    def test1(self):
        s = Solution()
        root = s.constructMaximumBinaryTree([3,2,1,6,0,5])
        self.assertEqual(6, root.val)
        self.assertEqual(3, root.left.val)
        self.assertEqual(5, root.right.val)
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()