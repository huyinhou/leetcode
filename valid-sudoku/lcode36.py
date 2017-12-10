import unittest


class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        bitmap = []
        for i in range(0, 9):
            rowbits = []
            for j in range(0, 9):
                rowbits.append(1022)
            bitmap.append(rowbits)
        for i in range(0, 9):
            for j in range(0, 9):
                ceil = ord(board[i][j]) - ord('0')
                if ceil < 0:
                    continue

                # print "ceil", i, j, ceil
                mask = 1 << ceil
                umask = ~mask
                if bitmap[i][j] & mask == 0:
                    return False
                
                for k in range(0, 9):
                    bitmap[i][k] &= umask
                    bitmap[k][j] &= umask
                m = (i / 3) * 3
                n = (j / 3) * 3
                for i1 in range(m, m + 3):
                    for j1 in range(n, n + 3):
                        bitmap[i1][j1] &= umask
        return True

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        board = [
            ["8", ".", ".", "5", "9", ".", ".", ".", "."],
            ["1", "7", "2", "8", ".", ".", ".", ".", "9"],
            [".", "3", ".", ".", ".", ".", ".", ".", "."],
            [".", "1", "3", ".", "5", ".", ".", "7", "4"],
            ["2", "6", ".", ".", "1", "9", "8", ".", "."],
            ["7", ".", ".", "3", "6", "4", "9", "2", "1"],
            ["4", ".", "7", ".", "2", "3", ".", "8", "6"],
            ["6", "2", ".", "9", "8", "5", "7", "4", "."],
            ["3", "8", "5", "6", "4", ".", "1", "9", "."]
        ]
        self.assertTrue(s.isValidSudoku(board))
    
def main():
    unittest.main()

if __name__ == '__main__':
    main()