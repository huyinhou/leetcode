
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
    int totalHammingDistance(vector<int>& nums) {
        int count[2][30] = {{0,0},{0,0}};

        for (int i = 0; i < nums.size(); i++) {
            int mask = 1;
            for (int j = 0; j < 30; j++) {
                if (mask & nums[i]) {
                    count[1][j]++;
                } else {
                    count[0][j]++;
                }
                mask <<= 1;
            }
        }
        int total = 0; 
        for (int i = 0; i < 30; i++) {
            total += count[0][i] * count[1][i];
        }
        return total;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {4, 14, 2};
    assert(s.totalHammingDistance(v1) == 6);
    return 0;
}
#endif
