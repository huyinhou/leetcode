/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 *
 * https://leetcode.com/problems/binary-gap/description/
 *
 * algorithms
 * Easy (59.28%)
 * Total Accepted:    21.1K
 * Total Submissions: 35.6K
 * Testcase Example:  '22'
 *
 * Given a positive integer N, find and return the longest distance between two
 * consecutive 1's in the binary representation of N.
 * 
 * If there aren't two consecutive 1's, return 0.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 22
 * Output: 2
 * Explanation: 
 * 22 in binary is 0b10110.
 * In the binary representation of 22, there are three ones, and two
 * consecutive pairs of 1's.
 * The first consecutive pair of 1's have distance 2.
 * The second consecutive pair of 1's have distance 1.
 * The answer is the largest of these two distances, which is 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: 2
 * Explanation: 
 * 5 in binary is 0b101.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 6
 * Output: 1
 * Explanation: 
 * 6 in binary is 0b110.
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: 8
 * Output: 0
 * Explanation: 
 * 8 in binary is 0b1000.
 * There aren't any consecutive pairs of 1's in the binary representation of 8,
 * so we return 0.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10^9
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
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
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

class Solution {
public:
    int binaryGap(int N) {
        int maxd = 0;
        int last1 = -1;
        unsigned mask = 1;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            if (mask & N) {
                if (last1 < 0) {
                    last1 = i;
                } else {
                    int d = i - last1;
                    if (maxd < d) {
                        maxd = d;
                    }
                    last1 = i;
                }
            }
            mask <<= 1;
        }
        return maxd;
    }
};


#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.binaryGap(0) == 0);
    assert(s.binaryGap(22) == 2);
    assert(s.binaryGap(5) == 2);
    assert(s.binaryGap(6) == 1);
    return 0;
}
#endif
