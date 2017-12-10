import unittest

class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        strmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        title = ""
        while n > 0:
            n = n - 1
            a = n % 26
            title = strmap[a] + title
            n = n / 26
        return title

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        ret = s.convertToTitle(1)
        self.assertEqual(ret, "A")
        ret = s.convertToTitle(26)
        self.assertEqual(ret, "Z")
        ret = s.convertToTitle(28)
        self.assertEqual(ret, "AB")

if __name__ == '__main__':
    unittest.main()

#a1 * 26^n-1 + a2 *26^n-2 +... + an - 1 = num - 1
#1 <= ai <= 26
# return "" if num == 0 else self.convertToTitle((num - 1) / 26) + strmap[(num - 1) % 26]
