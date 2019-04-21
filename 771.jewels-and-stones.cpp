/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 *
 * https://leetcode.com/problems/jewels-and-stones/description/
 *
 * algorithms
 * Easy (82.79%)
 * Total Accepted:    225.3K
 * Total Submissions: 271.6K
 * Testcase Example:  '"aA"\n"aAAbbbb"'
 *
 * You're given strings J representing the types of stones that are jewels, and
 * S representing the stones you have.  Each character in S is a type of stone
 * you have.  You want to know how many of the stones you have are also
 * jewels.
 * 
 * The letters in J are guaranteed distinct, and all characters in J and S are
 * letters. Letters are case sensitive, so "a" is considered a different type
 * of stone from "A".
 * 
 * Example 1:
 * 
 * 
 * Input: J = "aA", S = "aAAbbbb"
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: J = "z", S = "ZZ"
 * Output: 0
 * 
 * 
 * Note:
 * 
 * 
 * S and J will consist of letters and have length at most 50.
 * The characters in J are distinct.
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <stack>
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
    int numJewelsInStones(string J, string S) {
        if (J.empty() || S.empty()) {
            return 0;
        }
        // vector<bool> flags(64, false);
        uint64_t flags = 0;
        uint64_t mask = 1;
        int index = 0;
        char ch = '\0';
        for (size_t i = 0; i < J.size(); i++) {
            ch = J[i];
            if (ch >= 'A' && ch <= 'Z') {
                index = ch - 'A' + 32;
            } else if (ch >= 'a' && ch <= 'z') {
                index = ch - 'a';
            }
            flags |= (mask << index);
        }
        int ret = 0;
        for (size_t i = 0; i < S.size(); i++) {
            ch = S[i];
            if (ch >= 'A' && ch <= 'Z') {
                index = ch - 'A' + 32;
            } else if (ch >= 'a' && ch <= 'z') {
                index = ch - 'a';
            } else {
                continue;
            }
            if (flags & (mask << index)) {
                ret++;
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.numJewelsInStones("aA", "aAAbbbb") == 3);
    assert(s.numJewelsInStones("z", "ZZZZ") == 0);
    return 0;
}
#endif