
import unittest

class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        rows = len(matrix)
        if rows == 0:
            return []
        cols = len(matrix[0])
        nowrow = 0
        nowcol = -1
        retval = []
        while rows > 0 and cols > 0:
            # move right cols times
            # move down rows - 1 times
            # move left cols - 1 times
            # move top rows - 2 times
            if cols <= 0:
                break
            for i in range(cols):
                nowcol += 1
                retval.append(matrix[nowrow][nowcol])
            if rows - 1 <= 0:
                break
            for i in range(rows - 1):
                nowrow += 1
                retval.append(matrix[nowrow][nowcol])
            if cols - 1 <= 0:
                break
            for i in range(cols - 1):
                nowcol -= 1
                retval.append(matrix[nowrow][nowcol])
            if rows - 2 <= 0:
                break
            for i in range(rows - 2):
                nowrow -= 1
                retval.append(matrix[nowrow][nowcol])
            rows -= 2
            cols -= 2
        return retval

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        m = [
            [1, 2, 3, 4, 5],
            [6, 7, 8, 9, 10]
        ]
        self.assertEqual(10, len(s.spiralOrder(m)))
        m = [
            [1,],
            [2,],
            [3,]
        ]
        self.assertEqual(3, len(s.spiralOrder(m)))
        m = [
            [1, 2, 3, 4, 5]
        ]
        self.assertEqual(5, len(s.spiralOrder(m)))
        m = [
            [1, 1, 1, 1, 1],
            [2, 2, 2, 2, 2],
            [3, 3, 3, 3, 3],
            [4, 4, 4, 4, 4]
        ]
        self.assertEqual(20, len(s.spiralOrder(m)))
        m = [
            [1, 1, 1, 1, 1],
            [2, 2, 2, 2, 2],
            [3, 3, 3, 3, 3],
            [4, 4, 4, 4, 4],
            [5, 5, 5, 5, 5],
            [6, 6, 6, 6, 6]
        ]
        self.assertEqual(30, len(s.spiralOrder(m)))
        self.assertEqual([], s.spiralOrder([]))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()