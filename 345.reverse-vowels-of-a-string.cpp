/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (40.96%)
 * Total Accepted:    145.3K
 * Total Submissions: 354.7K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <string>
#include <algorithm>
using std::string;
#endif

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (!isVowel(s[i])) {
                i++;
                continue;
            }
            if (!isVowel(s[j])) {
                j--;
                continue;
            }
            std::swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }

    bool isVowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            return true;
        }
        return false;
    }
};

#ifdef LEETCODE
#include <iostream>

int main(int argc, char *argv[]) {
    Solution s;
    assert(s.reverseVowels("hello") == "holle");
    std::cout<<s.reverseVowels("leetcode")<<std::endl;
    assert(s.reverseVowels("leetcode") == "leotcede");
    assert(s.reverseVowels("") == "");
    return 0;
}
#endif
