/*
 * @lc app=leetcode id=807 lang=cpp
 *
 * [807] Max Increase to Keep City Skyline
 *
 * https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/
 *
 * algorithms
 * Medium (81.07%)
 * Total Accepted:    41.1K
 * Total Submissions: 50.6K
 * Testcase Example:  '[[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]'
 *
 * In a 2 dimensional array grid, each value grid[i][j] represents the height
 * of a building located there. We are allowed to increase the height of any
 * number of buildings, by any amount (the amounts can be different for
 * different buildings). Height 0 is considered to be a building as well. 
 * 
 * At the end, the "skyline" when viewed from all four directions of the grid,
 * i.e. top, bottom, left, and right, must be the same as the skyline of the
 * original grid. A city's skyline is the outer contour of the rectangles
 * formed by all the buildings when viewed from a distance. See the following
 * example.
 * 
 * What is the maximum total sum that the height of the buildings can be
 * increased?
 * 
 * 
 * Example:
 * Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
 * Output: 35
 * Explanation: 
 * The grid is:
 * [ [3, 0, 8, 4], 
 * ⁠ [2, 4, 5, 7],
 * ⁠ [9, 2, 6, 3],
 * ⁠ [0, 3, 1, 0] ]
 * 
 * The skyline viewed from top or bottom is: [9, 4, 8, 7]
 * The skyline viewed from left or right is: [8, 7, 9, 3]
 * 
 * The grid after increasing the height of buildings without affecting skylines
 * is:
 * 
 * gridNew = [ [8, 4, 8, 7],
 * ⁠           [7, 4, 7, 7],
 * ⁠           [9, 4, 8, 7],
 * ⁠           [3, 3, 3, 3] ]
 * 
 * 
 * 
 * Notes: 
 * 
 * 
 * 1 < grid.length = grid[0].length <= 50.
 * All heights grid[i][j] are in the range [0, 100].
 * All buildings in grid[i][j] occupy the entire grid cell: that is, they are a
 * 1 x 1 x grid[i][j] rectangular prism.
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rows(grid.size()), cols(grid.size());     // 每行/每列最大值
        for (size_t i = 0; i < grid.size(); i++) {
            vector<int> &line = grid[i];
            rows[i] = *std::max_element(line.begin(), line.end());
            for (size_t j = 0; j < cols.size(); j++) {
                cols[j] = std::max(cols[j], line[j]);
            }
        }
        int ret = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            vector<int> &line = grid[i];
            for (size_t j = 0; j < line.size(); j++) {
                ret += std::min(rows[i], cols[j]) - line[j];
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> l1{3, 0, 8, 4};
    vector<int> l2{2, 4, 5, 7};
    vector<int> l3{9, 2, 6, 3};
    vector<int> l4{0, 3, 1, 0};
    vector<vector<int> > grid;
    grid.push_back(l1);
    grid.push_back(l2);
    grid.push_back(l3);
    grid.push_back(l4);
    assert(s.maxIncreaseKeepingSkyline(grid) == 35);
    return 0;
}
#endif
