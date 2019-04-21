/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.37%)
 * Total Accepted:    391.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
// #define LEETEST
#ifdef LEETEST
#include <string>
using std::string;
#endif

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) {
            return 0;
        }
        if (haystack.length() < needle.length()) {
            return -1;
        }
        for (size_t i = 0; i <= haystack.length() - needle.length(); i++) {
            size_t j = 0;
            for (; j < needle.length(); j++) {
                if (haystack[i+j] != needle[j]) {
                    break;
                }
            }
            if (j == needle.length()) {
                return i;
            }
        }
        return -1;
    }
};

#ifdef LEETEST
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.strStr(string(), string("123")) == -1);
    assert(s.strStr(string("123"), string()) == 0);
    assert(s.strStr(string("123456"), string("3")) == 2);
    assert(s.strStr(string("samestr"), string("samestr")) == 0);
} 
#endif
