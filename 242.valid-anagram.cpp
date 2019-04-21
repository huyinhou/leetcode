/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (51.15%)
 * Total Accepted:    308.9K
 * Total Submissions: 603.9K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
// #define LEETCODE
#ifdef LEETCODE

#endif

#include <string>
using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int ns[26] = {0};
        int nt[26] = {0};
        for (size_t i = 0; i < s.size(); i++) {
            ns[s[i] - 'a']++;
        }
        for (size_t i = 0; i < t.size(); i++) {
            nt[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (ns[i] != nt[i]) {
                return false;
            }
        }
        return true;
    }
};

#ifdef LEETCODE
#include <cassert>

int main(int argc, char *argv[]) {
    Solution s;
    assert(s.isAnagram("anagram", "nagaram"));
    assert(!s.isAnagram("car", "cat"));
    return 0;
}
#endif
