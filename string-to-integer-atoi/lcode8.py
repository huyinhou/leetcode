import unittest

INT_MAX = 2147483647
INT_MIN = -2147483648

class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        # trim whitespace
        size = len(str)
        idx = 0
        while idx < size:
            if str[idx] != ' ':
                break
            idx += 1
        if idx >= size:
            return 0
        flag = 1
        if str[idx] == '+':
            idx += 1
        elif str[idx] == '-':
            flag = -1
            idx += 1
        num = 0
        while idx < size:
            c = ord(str[idx]) - ord('0')
            if c < 0 or c > 9:
                break
            temp = num * 10 + c
            if flag > 0:
                if temp > INT_MAX:
                    return INT_MAX
            else:
                if temp > -INT_MIN:
                    return INT_MIN
            num = temp
            idx += 1
        return flag * num

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(0, s.myAtoi("    "))
        self.assertEqual(0, s.myAtoi("- "))
        self.assertEqual(-1, s.myAtoi("-1"))
        self.assertEqual(12, s.myAtoi("12"))
        self.assertEqual(24, s.myAtoi("+24"))
        self.assertEqual(12, s.myAtoi(" 12sdfjk"))
        self.assertEqual(INT_MAX, s.myAtoi("2147483648"))
        self.assertEqual(INT_MIN, s.myAtoi("-2147483649"))

def main():
    unittest.main()

if __name__ == '__main__':
    main()