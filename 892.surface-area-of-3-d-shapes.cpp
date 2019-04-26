/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
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
#include <map>
#include <vector>
using namespace std;
#endif

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int td = 0, lr=0, fb = 0, tmp = 0;
        if (grid.empty()) {
            return 0;
        }
        // 计算边缘
        size_t last = grid.size() - 1;
        for (size_t i = 0; i < grid.size(); i++) {
            // 第i行
            lr += grid[i][0] + grid[i][last];
            // 第i列
            fb += grid[0][i] + grid[last][i];
        }
        // cout<<td<<" "<<lr<<" "<<fb<<""<<std::endl;
        // 计算中间
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid.size(); j++) {
                // 计算第i行，j列
                tmp = 0;
                vector<int> &row = grid[i];
                if (row[j] > 0) {
                    td += 2;
                }
                if (j > 0) {
                    lr += abs(row[j] - row[j - 1]);
                    fb += abs(grid[j][i] - grid[j - 1][i]);
                }
                
                // 计算第i列，j行
            }
        }
        // cout<<td<<" "<<lr<<" "<<fb<<""<<std::endl;
        return td + lr + fb;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int> > g1 = {
        {2}
    };
    assert(s.surfaceArea(g1) == 10);
    vector<vector<int> > g2 = {
        {1, 2},
        {3, 4}
    };
    assert(s.surfaceArea(g2) == 34);
    vector<vector<int> > g3 = {
        {1, 0},
        {0, 2}
    };
    assert(s.surfaceArea(g3) == 16);
    vector<vector<int> > g4 = {
        {1,1,1},{1,0,1},{1,1,1}
    };
    assert(s.surfaceArea(g4) == 32);
    vector<vector<int> > g5 = {
        {2,2,2},{2,1,2},{2,2,2}
    };
    assert(s.surfaceArea(g5) == 46);
    return 0;
}
#endif

