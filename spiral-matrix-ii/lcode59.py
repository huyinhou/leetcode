
import unittest

class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        if n <= 0:
            return []
        matrix = []
        for i in range(n):
            matrix.append([0] * n)
        
        rows = n
        cols = n
        nowrow = 0
        nowcol = -1
        counter = 1
        # retval = []
        while rows > 0 and cols > 0:
            # move right cols times
            # move down rows - 1 times
            # move left cols - 1 times
            # move top rows - 2 times
            if cols <= 0:
                break
            for i in range(cols):
                nowcol += 1
                matrix[nowrow][nowcol] = counter
                counter += 1
            if rows - 1 <= 0:
                break
            for i in range(rows - 1):
                nowrow += 1
                matrix[nowrow][nowcol] = counter
                counter += 1
            if cols - 1 <= 0:
                break
            for i in range(cols - 1):
                nowcol -= 1
                matrix[nowrow][nowcol] = counter
                counter += 1
            if rows - 2 <= 0:
                break
            for i in range(rows - 2):
                nowrow -= 1
                matrix[nowrow][nowcol] = counter
                counter += 1
            rows -= 2
            cols -= 2
        return matrix
    

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        print s.generateMatrix(1)
        print s.generateMatrix(2)
        print s.generateMatrix(3)
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()