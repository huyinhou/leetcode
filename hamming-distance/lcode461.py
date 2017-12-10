import unittest

class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        v = x ^ y
        # print v
        sum = 0
        mask = 1
        for i in range(32):

            if v & mask != 0:
                sum += 1
            mask <<= 1
        return sum

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(2, s.hammingDistance(1, 4))


def main():
    unittest.main()

if __name__ == '__main__':
    main()