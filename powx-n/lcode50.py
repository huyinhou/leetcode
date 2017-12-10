import unittest

class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1
        if n < 0:
            n = -n
            x = 1.0 / x
            
        if n % 2 == 0:
            return self.myPow(x * x, n / 2)
        return x * self.myPow(x * x, n / 2)

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertAlmostEqual(1, s.myPow(1, 2))
        self.assertAlmostEqual(1, s.myPow(1000, 0))
        self.assertAlmostEqual(100.0, s.myPow(10, 2))
        self.assertAlmostEqual(0.01, s.myPow(10.0, -2))
        self.assertAlmostEqual(-0.001, s.myPow(-10.0, -3))
        self.assertAlmostEqual(10000, s.myPow(10.0, 4))
        self.assertAlmostEqual(0.0001, s.myPow(10.0, -4))
        s.myPow(0.00001, 2147483647)
        pass


def main():
    unittest.main()

if __name__ == '__main__':
    main()