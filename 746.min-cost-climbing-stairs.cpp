/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
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
    int minCostClimbingStairs(vector<int>& cost) {
        int step0 = 0, step1 = 0;
        for (int i = 0; i < cost.size(); i++) {
            int mcost = cost[i] + step1;
            if (step1 > step0) {
                mcost = cost[i] + step0;
            }
            step0 = step1;
            step1 = mcost;
        }
        if (step0 < step1) {
            return step0;
        }
        return step1;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {10, 15, 20};
    assert(s.minCostClimbingStairs(v1) == 15);
    vector<int> v2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    assert(s.minCostClimbingStairs(v2) == 6);
    return 0;
}
#endif

