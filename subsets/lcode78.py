
import unittest

class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 0:
            return [[],]
        sub = self.subsets(nums[1:])
        # print nums, sub
        tmp = sub[:]
        for s in sub:
            v = [nums[0],]
            v.extend(s)
            tmp.append(v)
        return tmp


class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        print s.subsets([1, 2, 3])
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()