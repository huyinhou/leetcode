import unittest

class Solution(object):
    def __init__(self):
        self.offset = None
        self.matrix = None

    # c(n, m) = c(n-1, m-1) + c(n-1, m)
    def c(self, n, m):
        if n < m:
            return 0
        if m < 0:
            return 0
        idx = self.offset[n] + m
        val = self.matrix[idx]
        if n == 0:
            return val
        if val != 0:
            return val
        val = self.c(n - 1, m - 1) + self.c(n - 1, m)
        self.matrix[idx] = val
        print n, m, val
        return val

    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        total = (n + m) - 2
        if total <= 0:
            return 1
        self.offset = [0] * (total + 1)
        
        for i in range(1, total + 1):
            self.offset[i] = self.offset[i - 1] + i
        print self.offset
        self.matrix = [0] * (self.offset[total] + total + 1)
        for i in range(total + 1):
            self.matrix[self.offset[i]] = 1
        print total
        print len(self.matrix)
        if m < n:
            return self.c(total, m - 1)
        return self.c(total, n - 1)

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(28, s.uniquePaths(3, 7))
        self.assertEqual(252, s.uniquePaths(6, 6))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()