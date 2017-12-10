
import unittest

# A Linear Time Majority Vote Algorithm
# http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        major = 0
        count = 0
        for val in nums:
            if count == 0 :
                major = val
                count = 1
            elif major == val:
                count += 1
            else:
                count -= 1
        return major


class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        ret = s.majorityElement([1, 2, 3, 1, 2, 3, 2, 2, 2, 2])
        self.assertEqual(ret, 2)


def main():
    unittest.main()

if __name__ == '__main__':
    main()