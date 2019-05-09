/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
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
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
using namespace std;
#endif

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> cntmap;
        for (int i = 0; i < nums.size(); i++) {
            cntmap[nums[i]]++;
        }
        int maxseq = 0;
        for (auto it = cntmap.begin(); it != cntmap.end(); it++) {
            auto it2 = cntmap.find(it->first + 1);
            if (it2 != cntmap.end()) {
                if (maxseq < it->second + it2->second) {
                    maxseq = it->second + it2->second;
                }
            }
        }
        return maxseq;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,3,2,2,5,2,3,7};
    assert(s.findLHS(v1) == 5);
    return 0;
}
#endif


