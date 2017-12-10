import unittest

class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        rows = len(matrix)
        if rows == 0:
            return False
        cols = len(matrix[0])
        if cols == 0:
            return False

        i = 0; j = rows
        while i < j:
            k = (i + j) / 2
            val = matrix[k][0]
            if val == target:
                return True
            elif val < target:
                i = k + 1
            else:
                j = k

        ridx = i - 1
        # print target, ridx
        if ridx < 0:
            return False

        i = 0; j = cols
        # print cols
        while i < j:
            k = (i + j) / 2
            val = matrix[ridx][k]
            if val == target:
                return True
            elif val < target:
                i = k + 1
            else:
                j = k
        return False

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        matrix = [
            [1, 3, 5, 7],
            [9, 11, 13, 15],
            [17, 21, 23, 24],
            [25, 26, 27, 28]
        ]
        self.assertTrue(s.searchMatrix(matrix, 1))
        self.assertFalse(s.searchMatrix(matrix, 0))
        self.assertTrue(s.searchMatrix(matrix, 7))
        self.assertFalse(s.searchMatrix(matrix, 8))
        self.assertTrue(s.searchMatrix(matrix, 17))
        self.assertFalse(s.searchMatrix(matrix, 29))
        self.assertFalse(s.searchMatrix([], 3))
        self.assertFalse(s.searchMatrix([[]], 2))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()