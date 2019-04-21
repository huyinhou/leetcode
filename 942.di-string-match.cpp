/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 *
 * https://leetcode.com/problems/di-string-match/description/
 *
 * algorithms
 * Easy (70.19%)
 * Total Accepted:    25.8K
 * Total Submissions: 36.9K
 * Testcase Example:  '"IDID"'
 *
 * Given a string S that only contains "I" (increase) or "D" (decrease), let N
 * = S.length.
 * 
 * Return any permutation A of [0, 1, ..., N] such that for all i = 0, ...,
 * N-1:
 * 
 * 
 * If S[i] == "I", then A[i] < A[i+1]
 * If S[i] == "D", then A[i] > A[i+1]
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "IDID"
 * Output: [0,4,1,3,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "III"
 * Output: [0,1,2,3]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "DDI"
 * Output: [3,2,0,1]
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 10000
 * S only contains characters "I" or "D".
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
    vector<int> diStringMatch(string s) {
        vector<int> ret;
        int m = 0, n = s.size();
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                ret.push_back(m++);
            } else if (s[i] == 'D') {
                ret.push_back(n--);
            }
        }
        ret.push_back(m);
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> ret = s.diStringMatch("IDID");
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    ret = s.diStringMatch("III");
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<int>(cout, ", "));
    return 0;
}
#endif

