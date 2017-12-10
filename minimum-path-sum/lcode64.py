# -*- coding:utf-8 -*-
import unittest

class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        nrow = len(grid)
        if nrow == 0:
            return 0
        ncol = len(grid[0])
        if ncol == 0:
            return 0
        matrix = [None] * nrow
        for i in range(nrow):
            matrix[i] = [None] * ncol
        grid = grid
        matrix[0][0] = grid[0][0]
        for i in range(nrow):
            for j in range(ncol):
                # print i, j
                val = matrix[i][j]
                if val is not None:
                    continue
                if i == 0:
                    matrix[i][j] = matrix[i][j - 1] + grid[i][j]
                elif j == 0:
                    matrix[i][j] = matrix[i - 1][j] + grid[i][j]
                else:
                    matrix[i][j] = min([matrix[i][j - 1], matrix[i - 1][j]]) + grid[i][j]
                    
        # print matrix
        return matrix[nrow - 1][ncol - 1]

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        grid = [
            [1, 2, 3, 4, 5],
            [-10, 2, 3, -5, 0],
            [1, 2, 0, 0, 1]
        ]
        self.assertEqual(-8, s.minPathSum(grid))
        pass

def main():
    unittest.main()
    # print '胡嘉睿'
    pass

if __name__ == '__main__':
    main()