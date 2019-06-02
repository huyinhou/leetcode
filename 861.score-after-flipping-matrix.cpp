
#define LEETCODE
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
#include <map>
#include <queue>
using namespace std;
#endif

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        // 翻转所有行
        vector<int> ones(A[0].size());
        ones[0] = A.size();
        for (int i = 0; i < A.size(); i++) {
            vector<int> &row = A[i];
            int first = row[0];
            if (first) {
                for (int j = 1; j < row.size(); j++) {
                    ones[j] += row[j];
                }
            } else {
                for (int j = 1; j < row.size(); j++) {
                    ones[j] += 1 - row[j];
                }
            }
        }
        int total = 0;
        for (int i = 0; i < ones.size(); i++) {
            total += std::max((int)(A.size() - ones[i]), ones[i]) * (1 << (ones.size() - 1 - i));
        }
        return total;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v1 = {
        {0,0,1,1},
        {1,0,1,0},
        {1,1,0,0}
    };
    cout<<s.matrixScore(v1)<<std::endl;
    return 0;
}
#endif
