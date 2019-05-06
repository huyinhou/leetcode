/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cmath>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
#endif

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ret;
        ret.resize(M.size());
        for (int i = 0; i < ret.size(); i++) {
            ret[i].resize(M[0].size());
            vector<int> &row = ret[i];
            for (int j = 0; j < row.size(); j++) {
                row[j] = smoothCell(i, j, M);
            }
        }
        return ret;
    }

    int smoothCell(int i, int j, vector<vector<int>>& M) {
        int total = 0, count = 0;
        int rmin = std::max(i - 1, 0), rmax = std::min(i + 2, static_cast<int>(M.size()));
        int cmin = std::max(j - 1, 0), cmax = std::min(j + 2, static_cast<int>(M[0].size()));
        for (int r = rmin; r <rmax; r++) {
            for (int c = cmin; c < cmax; c++) {
                total += M[r][c];
                count ++;
            }
        }
        // cout<<total <<" "<<count<<std::endl;
        total = static_cast<int>(floor((total * 1.0) / count));
        return total;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v1 = {
        {1,1,1,1},
        {1,0,1,3},
        {1,1,1,1}
    };
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v1[i].size(); j++) {
            cout<<s.smoothCell(i, j, v1)<<" ";
        }
        cout<<std::endl;
    }
    assert(s.smoothCell(0, 0, v1) == 0);

    return 0;
}
#endif

