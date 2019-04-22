/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 *
 * https://leetcode.com/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (62.79%)
 * Total Accepted:    34K
 * Total Submissions: 53.9K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * Given a string S and a character C, return an array of integers representing
 * the shortest distance from the character C in the string.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "loveleetcode", C = 'e'
 * Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S string length is in [1, 10000].
 * C is a single character, and guaranteed to be in string S.
 * All letters in S and C are lowercase.
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
#include <sstream>
#include <map>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
using std::map;
#endif

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ret(S.size(), INT_MAX);
        size_t pidx = 0;
        size_t idx = S.find(C, 0);
        while (true) {
            size_t i = 0;
            ret[idx] = 0;
            for (i = pidx; i < idx; i++) {
                if (ret[i] > idx - i) {
                    ret[i] = idx - i;
                }
            }
            pidx = idx;
            for (i = idx + 1; i < S.size(); i++) {
                if (S[i] == C) {
                    idx = i;
                    break;
                }
                if (ret[i] > i - idx) {
                    ret[i] = i - idx;
                }
            }
            if (i == S.size()) {
                break;
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    auto ret = s.shortestToChar("loveleetcode", 'l');
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    ret = s.shortestToChar("loveleetcode", 'e');
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
