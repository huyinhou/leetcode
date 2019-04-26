/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
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
    int rotatedDigits(int N) {
        int total = 0;
        vector<int> dp;
        dp.resize(N+1);
        for (int i = 0; i <= N; i++) {
            if (i < 10) {
                switch (i) {
                    case 2:
                    case 5:
                    case 6:
                    case 9:
                    dp[i] = 2;
                    total++;
                    break;

                    case 0:
                    case 1:
                    case 8:
                    dp[i] = 1;
                    break;

                    default:
                    dp[i] = 0;
                }
                continue;
            }

            int tmp = dp[i / 10] * dp[i % 10];
            if (tmp >= 2) {
                tmp = 2;
            }
            // cout<<i<<" "<<tmp<<std::endl;
            dp[i] = tmp;
            if (tmp == 2) {
                total++;
            }
        }
        return total;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.rotatedDigits(10) == 4);
    assert(s.rotatedDigits(20) == 9);
    return 0;
}
#endif
