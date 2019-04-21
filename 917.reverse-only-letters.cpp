/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 *
 * https://leetcode.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (55.99%)
 * Total Accepted:    23K
 * Total Submissions: 41.2K
 * Testcase Example:  '"ab-cd"'
 *
 * Given a string S, return the "reversed" string where all characters that are
 * not a letter stay in the same place, and all letters reverse their
 * positions.
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
 * Input: "ab-cd"
 * Output: "dc-ba"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "a-bC-dEf-ghIj"
 * Output: "j-Ih-gfE-dCba"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "Test1ng-Leet=code-Q!"
 * Output: "Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S.length <= 100
 * 33 <= S[i].ASCIIcode <= 122 
 * S doesn't contain \ or "
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
    static bool isletter(char ch) {
        return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
    }

    string reverseOnlyLetters(string S) {
        if (S.empty()) {
            return S;
        }

        size_t i = 0, j = S.size() - 1;
        while (i < j) {
            if (!isletter(S[i])) {
                i++;
                continue;
            }
            if (!isletter(S[j])) {
                j--;
                continue;
            }
            char ch = S[i];
            S[i] = S[j];
            S[j] = ch;
            i++;
            j--;
        }
        return S;
    }
};

#ifdef LEETCODE

int main(int argc, char *argv[]) {
    Solution s;
    assert(s.reverseOnlyLetters("ab-cd") == "dc-ba");
    assert(s.reverseOnlyLetters("a-bC-dEf-ghIj") == "j-Ih-gfE-dCba");
    assert(s.reverseOnlyLetters("Test1ng-Leet=code-Q!") == "Qedo1ct-eeLg=ntse-T!");
    return 0;
}
#endif
