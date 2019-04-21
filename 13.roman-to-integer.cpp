/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (51.72%)
 * Total Accepted:    375.4K
 * Total Submissions: 725.9K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
using std::string;
using std::cout;

class Solution {
public:
    static constexpr int roman[26] = {
        0,  0,  100, 500,   0,  0,    0,        /* A, B, C, D, E, F, G */
        0,  1,  0,   0,     50, 1000, 0,        /* H, I, J, K, L, M, N */
        0,  0,  0,          0,  0,    0,        /* O, P, Q, R, S, T */
        0,  5,  0,          10, 0,   0          /* U, V, W, X, Y, Z */
    };

    int romanToInt(string s) {
        std::vector<int> digits(s.length());
        for (size_t i = 0; i < s.length(); i++) {
            digits[i] = roman[s[i] - 'A'];
        }
        int total = 0;
        for (size_t i = 0; i < digits.size(); i++) {
            if (i + 1 < digits.size()) {
                if (digits[i] < digits[i+1]) {
                    total += -digits[i];
                    continue;
                }
            }
            total += digits[i];
        }
        return total;
    }
};
constexpr int Solution::roman[26];

// int main(int argc, char* argv[]) {
//     Solution s;

//     assert(s.romanToInt("MMMCCCXXXIII") == 3333);
//     assert(s.romanToInt("MCDXXXVII") == 1437);
//     assert(s.romanToInt("MCMXCIV") == 1994);
//     return 0;
// }
