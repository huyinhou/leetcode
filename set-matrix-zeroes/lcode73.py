import unittest

class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        row0 = False
        col0 = False
        rows = len(matrix)
        cols = len(matrix[0])
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    if i == 0:
                        row0 = True
                    if j == 0:
                        col0 = True
                    matrix[0][j] = 0
                    matrix[i][0] = 0
        for i in range(1, rows):
            for j in range(1, cols):
                if matrix[i][0] == 0 or \
                    matrix[0][j] == 0:
                    matrix[i][j] = 0
        if row0:
            for j in range(cols):
                matrix[0][j] = 0
        if col0:
            for i in range(rows):
                matrix[i][0] = 0
        

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        matrix = [
            [1, 2, 3],
            [2, 3, 0],
            [3, 0, 1]
        ]
        s.setZeroes(matrix)
        self.assertEqual([1, 0, 0], matrix[0])
        self.assertEqual([0, 0, 0], matrix[1])
        self.assertEqual([0, 0, 0], matrix[2])
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()