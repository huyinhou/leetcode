
#define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
using namespace std;

 #endif

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int nfresh = 0;
        vector<short> rotten; 
        for (size_t i = 0; i < grid.size(); i++) {
            vector<int> &row = grid[i];
            for (size_t j = 0; j < row.size(); j++) {
                if (row[j] == 1) {
                    nfresh++;
                } else if (row[j] == 2) {
                    rotten.push_back((i << 8) + j);
                }
            }
        }
        int nminute = 0;
        while (nfresh > 0 && !rotten.empty()) {
            vector<short> temp;
            for (size_t i = 0; i < rotten.size(); i++) {
                short pos = rotten[i];
                int r = pos >> 8;
                int c = pos & 0xFF;
                makeRotten(grid, r - 1, c, nfresh, temp);
                makeRotten(grid, r + 1, c, nfresh, temp);
                makeRotten(grid, r, c - 1, nfresh, temp);
                makeRotten(grid, r, c + 1, nfresh, temp);
            }
            nminute++;
            rotten.swap(temp);
        }
        if (nfresh == 0) {
            return nminute;
        }
        return -1;
    }

    void makeRotten(vector<vector<int>>& grid, int r, int c, int &nfresh, vector<short> &temp) {
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1) {
            nfresh--;
            temp.push_back((r << 8) + c);
            grid[r][c] = 2;
        }
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v1 = {{2,1,1},{1,1,0},{0,1,1}};
    assert(s.orangesRotting(v1) == 4);
    vector<vector<int>> v2 = {{2,1,1},{0,1,1},{1,0,1}};
    assert(s.orangesRotting(v2) == -1);
    return 0;
}
#endif


