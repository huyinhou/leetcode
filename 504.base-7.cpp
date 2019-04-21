/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (44.61%)
 * Total Accepted:    39.7K
 * Total Submissions: 88.8K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
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

class Solution {
public:
    string convertToBase7(int num) {
        bool negative = num < 0;
        if (negative) {
            num = -num;
        }
        string ret;
        do {
            int a = num % 7;
            num /= 7;
            ret.insert(ret.begin(), a + '0');
        } while(num > 0);
        if (negative) {
            ret.insert(ret.begin(), '-');
        }
        return ret;
    }
};

#ifdef LEETCODE

int main(int argc, char *argv[]) {
    Solution s;
    assert(s.convertToBase7(100) == "202");
    assert(s.convertToBase7(0) == "0");
    assert(s.convertToBase7(-7) == "-10");
    return 0;
}
#endif
