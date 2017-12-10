import unittest

INT_MAX = 2147483647
INT_MIN = -2147483648
class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if divisor == 0 or \
            (dividend == INT_MIN and divisor == -1):
            return INT_MAX
        flag = 0
        if dividend < 0:
            flag ^= 1
            dividend = -dividend
        if divisor < 0:
            flag ^= 1
            divisor = -divisor
        if dividend < divisor:
            return 0
        shift = 0
        while (divisor << shift) <= dividend:
            shift += 1
        shift -= 1
        remainder = (1<<shift) + self.divide(dividend - (divisor << shift), divisor)
        if flag:
            return -remainder
        return remainder

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(1, s.divide(5, 3))
        self.assertEqual(2, s.divide(6, 3))
        self.assertEqual(INT_MAX - 1, s.divide(INT_MAX - 1, 1))
        self.assertEqual(INT_MAX, s.divide(3, 0))
        self.assertEqual(INT_MAX, s.divide(INT_MIN, -1))
        self.assertEqual(-3, s.divide(6, -2))
        self.assertEqual(-3, s.divide(-6, 2))
        self.assertEqual(3, s.divide(-6, -2))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()