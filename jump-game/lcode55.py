import unittest

class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        maxreach = 0
        for i in range(len(nums)):
            if i > maxreach:
                return False
            maxreach = max(maxreach, i + nums[i])
        return True

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertTrue(s.canJump([2,3,1,1,4]))
        self.assertFalse(s.canJump([3,2,1,0,4]))
        self.assertFalse(s.canJump([0, 1, 2, 3, 4]))
        self.assertTrue(s.canJump([0]))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()