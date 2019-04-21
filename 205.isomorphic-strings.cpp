/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (36.81%)
 * Total Accepted:    190K
 * Total Submissions: 516.1K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */
#include <string>
using std::string;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char smap[256] = { 0 };
        char tmap[256] = { 0 };
        for (size_t i = 0; i < s.size(); i++) {
            if (smap[s[i]] == 0) {
                if (tmap[t[i]] == 0) {
                    smap[s[i]] = t[i];
                    tmap[t[i]] = s[i];
                } else {
                    return false;
                }
            } else if (t[i] != smap[s[i]]) {
                return false;
            }
        }
        return true;
    }
};

// #define LEETEST
#ifdef LEETEST
int main(int argc, char *argv[]) {
    Solution s;
    assert(!s.isIsomorphic("foo", "bar"));
    assert(s.isIsomorphic("foo", "daa"));
    assert(s.isIsomorphic("paper", "title"));
    assert(!s.isIsomorphic("ab", "aa"));
    return 0;
}
#endif
