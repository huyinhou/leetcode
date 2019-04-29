/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
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
#include <map>
using namespace std;
#endif

class Solution {
public:
    struct NumberInfo {
        NumberInfo(){
            degree = 0;
            first = -1;
            last = -1;
        }
        int degree;
        int first;
        int last;
    };

    int findShortestSubArray(vector<int>& nums) {
        map<int, NumberInfo> numMap;
        for (size_t i = 0; i < nums.size(); i++) {
            NumberInfo &val = numMap[nums[i]];
            val.degree++;
            if (val.first < 0) {
                val.first = i;
            }
            val.last = i;
        }
        int maxd = INT_MIN, length = INT_MAX;
        for (auto it = numMap.begin(); it != numMap.end(); it++) {
            NumberInfo &val = it->second;
            int len = val.last - val.first + 1;
            if (val.degree > maxd) {
                maxd = val.degree;
                length = len;
            } else if (val.degree == maxd) {
                if (length > len) {
                    length = len;
                }
            }
        }
        return length;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1{1, 2, 2, 3, 1};
    assert(s.findShortestSubArray(v1) == 2);
    vector<int> v2{1,2,2,3,1,4,2};
    assert(s.findShortestSubArray(v2) == 6);
    return 0;
}
#endif
