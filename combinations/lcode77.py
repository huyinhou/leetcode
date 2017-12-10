
import unittest

class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        # print n, k
        if k <= 0:
            return [[],]
        if k > n:
            return []
        elif k == n:
            return [[i for i in range(1, n + 1)],]

        n1 = self.combine(n - 1, k - 1)
        for l in n1:
            l.append(n)
        n0 = self.combine(n - 1, k)
        # print n1, n0
        n1.extend(n0)
        return n1

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        print s.combine(2, 1)
        print s.combine(2, 0)
        print s.combine(3, 1)
        print s.combine(5, 4)
        print s.combine(4, 2)
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()