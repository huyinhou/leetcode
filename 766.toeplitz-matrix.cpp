
#define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
using std::map;
using std::set;
#endif


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return true;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        // 起始点位置
        int r = rows - 1, c = 0;
        while (c < cols) {
            int num = matrix[r][c];
            int r1 = r + 1, c1 = c + 1;
            while (r1 < rows && c1 < cols) {
                if (matrix[r1][c1] != num) {
                    return false;
                }
                r1++;
                c1++;
            }
            if (--r < 0) {
                r = 0;
                c++;
            }
        }
        return true;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v1 = {
        {1,2,3,4},
        {5,1,2,3},
        {9,5,1,2}
    };
    assert(s.isToeplitzMatrix(v1));
    
    vector<vector<int>> v2 = {
        {1,2},{2,2}
    };
    assert(!s.isToeplitzMatrix(v2));
    return 0;
}
#endif

