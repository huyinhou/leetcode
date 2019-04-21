/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (36.71%)
 * Total Accepted:    53.3K
 * Total Submissions: 144.9K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * 
 * Input: "Hello, my name is John"
 * Output: 5
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

class Solution {
public:
    int countSegments(string s) {
        int lastch = -1;
        int total = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (isspace(s[i])) {
                if (lastch >= 0) {
                    total++;
                    lastch = -1;
                }
            } else {
                if (lastch < 0) {
                    lastch = i;
                }
            }
        }
        return total + (lastch >= 0);
    }
};

#ifdef LEETCODE
#include <iostream>
#include <cassert>
#include <sstream>
using std::ostringstream;

int main(int argc, char *argv[]) {
    Solution s;
    assert(s.countSegments("hello, aaa  dd") == 3);
    assert(s.countSegments("") == 0);
    assert(s.countSegments("  aa, dd ff ") == 3);
    assert(s.countSegments("aa") == 1);
    return 0;
}
#endif

