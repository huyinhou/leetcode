import unittest

class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        size = len(matrix)
        for i in range(size):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for i in range(size):
            a = 0
            b = size - 1
            while a < b:
                matrix[i][a], matrix[i][b] = matrix[i][b], matrix[i][a]
                a += 1
                b -= 1
        
class TestSolution(unittest.TestCase):
    def test_1(self):
        matrix = [
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]
        ]
        s = Solution()
        s.rotate(matrix)
        print matrix
        matrix = [
            [1, 2, 3, 4],
            [5, 6, 7, 8],
            [9, 1, 2, 3],
            [4, 5, 6, 7]
        ]
        s.rotate(matrix)
        print matrix
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()