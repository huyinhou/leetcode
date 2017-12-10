
import unittest

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i = 0
        j = len(height) - 1
        water = 0
        while i < j:
            minh = min(height[i], height[j])
            water = max(water, minh * (j - i))
            while(height[i] <= minh and i < j):
                i += 1
            while(height[j] <= minh and i < j):
                j -= 1
        return water

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(12, s.maxArea([1, 2, 3, 2, 3, 2, 5, 1]))

def main():
    unittest.main()

if __name__ == '__main__':
    main()