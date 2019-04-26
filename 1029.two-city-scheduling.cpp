
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
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] + costs[j - 1][1];
        }
        for (int i = 1; i <= n; i++) {
            dp[0] += costs[i - 1][0];
            for (int j = 1; j <= n; j++) {
                dp[j] = std::min(dp[j - 1] + costs[i + j - 1][1], dp[j] + costs[i + j - 1][0]);
            }
        }
        return dp[n];
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int> > c1={
        {10,20},
        {30,200},
        {400,50},
        {30,20}
    };
    assert(s.twoCitySchedCost(c1) == 110);
    return 0;
}
#endif