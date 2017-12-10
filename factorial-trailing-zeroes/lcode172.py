# -*- coding: utf-8 -*-

import unittest

# 将每个数分解成2和5的形式，2的个数肯定大于5的个数，所以，只需统计出现了多少个5即可
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        ret = 0
        while n > 0:
            n = n / 5
            ret += n
        return ret

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(2, s.trailingZeroes(10))

def main():
    unittest.main()

if __name__ == '__main__':
    main()