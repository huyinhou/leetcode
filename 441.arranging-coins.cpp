/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 *
 * https://leetcode.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (37.57%)
 * Total Accepted:    66.4K
 * Total Submissions: 176.2K
 * Testcase Example:  '5'
 *
 * You have a total of n coins that you want to form in a staircase shape,
 * where every k-th row must have exactly k coins.
 * ⁠
 * Given n, find the total number of full staircase rows that can be formed.
 * 
 * n is a non-negative integer and fits within the range of a 32-bit signed
 * integer.
 * 
 * Example 1:
 * 
 * n = 5
 * 
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤
 * 
 * Because the 3rd row is incomplete, we return 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * n = 8
 * 
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 * 
 * Because the 4th row is incomplete, we return 3.
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

#include <cmath>

class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 0) {
            return 0;
        }

        unsigned k = unsigned(floor(sqrt(2.0 * n)));
        unsigned m = 1;
        do {
            if (k % 2 == 0) {
                m = k / 2 * (k + 1);
            } else {
                m = (k + 1) / 2 * k;
            }
            // cout<<k<<", "<<m<<std::endl;
            if (m > n) {
                return k - 1;
            }
            k++;
        } while (true);
        return 0;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.arrangeCoins(0) == 0);
    assert(s.arrangeCoins(1) == 1);
    assert(s.arrangeCoins(2) == 1);
    assert(s.arrangeCoins(4) == 2);
    assert(s.arrangeCoins(7) == 3);
    assert(s.arrangeCoins(12) == 4);
    assert(s.arrangeCoins(2147483647) == 65535);
    assert(s.arrangeCoins(1967513926) == 62729);
    return 0;
}
#endif
