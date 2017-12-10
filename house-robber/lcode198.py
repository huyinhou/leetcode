import unittest

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        rmax = 0
        nmax = 0
        for val in nums :
            r = val + nmax
            n = rmax
            nmax = max([n, nmax])
            rmax = max([r, rmax])
            
        return max(rmax, nmax)

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(5, s.rob[1, 5, 2])

def main():
    unittest.main()

if __name__ == '__main__':
    main()