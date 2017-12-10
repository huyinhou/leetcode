import unittest

class Solution(object):
    def __init__(self):
        self.matrix = None
        self.obstacle = None

    def dp(self, row, col):
        if row < 0 or col < 0:
            return 0
        val = self.matrix[row][col]
        if val >= 0:
            return val
        if self.obstacle[row][col] == 1:
            val = 0
        else:
            val = self.dp(row - 1, col) + self.dp(row, col - 1)
        self.matrix[row][col] = val
        # print row, col, val
        return val

    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        nrow = len(obstacleGrid)
        if nrow == 0:
            return 0
        ncol = len(obstacleGrid[0])
        if ncol == 0:
            return 0
        
        self.matrix = [None] * nrow
        for i in range(nrow):
            self.matrix[i] = [-1] * ncol
        self.obstacle = obstacleGrid
        if obstacleGrid[0][0] == 1:
            return 0
        self.matrix[0][0] = 1
        return self.dp(nrow - 1, ncol - 1)

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        grid = [
            [0, 0, 0, 0, 0],
            [0, 0, 1, 0, 0],
            [0, 1, 0, 0, 0]
        ]
        self.assertEqual(3, s.uniquePathsWithObstacles(grid))
        grid = [
            [1, 0, 0, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0]
        ]
        self.assertEqual(0, s.uniquePathsWithObstacles(grid))
        grid = [
            [0, 0, 0, 0],
            [0, 0, 0, 1]
        ]
        self.assertEqual(0, s.uniquePathsWithObstacles(grid))
        grid = [
            [0, 0, 0],
            [0, 1, 0],
            [0, 0, 0]
        ]
        self.assertEqual(2, s.uniquePathsWithObstacles(grid))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()