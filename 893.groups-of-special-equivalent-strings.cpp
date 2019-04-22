/*
 * @lc app=leetcode id=893 lang=cpp
 *
 * [893] Groups of Special-Equivalent Strings
 *
 * https://leetcode.com/problems/groups-of-special-equivalent-strings/description/
 *
 * algorithms
 * Easy (61.70%)
 * Total Accepted:    13.2K
 * Total Submissions: 21.3K
 * Testcase Example:  '["a","b","c","a","c","c"]'
 *
 * You are given an array A of strings.
 * 
 * Two strings S and T are special-equivalent if after any number of moves, S
 * == T.
 * 
 * A move consists of choosing two indices i and j with i % 2 == j % 2, and
 * swapping S[i] with S[j].
 * 
 * Now, a group of special-equivalent strings from A is a non-empty subset S of
 * A such that any string not in S is not special-equivalent with any string in
 * S.
 * 
 * Return the number of groups of special-equivalent strings from A.
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
 * Input: ["a","b","c","a","c","c"]
 * Output: 3
 * Explanation: 3 groups ["a","a"], ["b"], ["c","c","c"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["aa","bb","ab","ba"]
 * Output: 4
 * Explanation: 4 groups ["aa"], ["bb"], ["ab"], ["ba"]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["abc","acb","bac","bca","cab","cba"]
 * Output: 3
 * Explanation: 3 groups ["abc","cba"], ["acb","bca"], ["bac","cab"]
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: ["abcd","cdab","adcb","cbad"]
 * Output: 1
 * Explanation: 1 group ["abcd","cdab","adcb","cbad"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 1000
 * 1 <= A[i].length <= 20
 * All A[i] have the same length.
 * All A[i] consist of only lowercase letters.
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
#include <sstream>
#include <map>
#include <set>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
using std::map;
using std::set;
#endif

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int count[26];
        set<string> group;
        for (size_t i = 0; i < A.size(); i++) {
            string &str = A[i];
            ostringstream oss;
            memset(count, 0, sizeof(count));
            for (size_t k = 0; k <str.size(); k+=2) {
                count[str[k] - 'a']++;
            }
            for (size_t k = 0; k < 26; k++) {
                if (count[k]) {
                    oss<<'a'+k<<count[k];
                }
            }
            oss<<'|';
            memset(count, 0, sizeof(count));
            for (size_t k = 1; k <str.size(); k+=2) {
                count[str[k] - 'a']++;
            }
            for (size_t k = 0; k < 26; k++) {
                if (count[k]) {
                    oss<<'a'+k<<count[k];
                }
            }
            group.insert(oss.str());
        }
        return group.size();
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<string> v1{"a","b","c","a","c","c"};
    assert(s.numSpecialEquivGroups(v1) == 3);
    vector<string> v2{"aa","bb","ab","ba"};
    assert(s.numSpecialEquivGroups(v2) == 4);
    vector<string> v3{"abc","acb","bac","bca","cab","cba"};
    assert(s.numSpecialEquivGroups(v3) == 3);
    vector<string> v4{"abcd","cdab","adcb","cbad"};
    assert(s.numSpecialEquivGroups(v4) == 1);
    return 0;
}
#endif
