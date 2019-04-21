/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (43.14%)
 * Total Accepted:    89.5K
 * Total Submissions: 206.3K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
using std::string;
using std::ostringstream;
#endif

class Solution {
public:
    string addStrings(string num1, string num2) {
        size_t maxsize = num1.size();
        if (maxsize < num2.size()) {
            maxsize = num2.size();
        }
        string result;
        result.reserve(maxsize + 1);
        int carray = 0, digit = 0;
        string::reverse_iterator it1 = num1.rbegin(), it2 = num2.rbegin();
        while((it1 != num1.rend()) && (it2 != num2.rend())) {
            digit = *it1 - '0' + *it2 - '0' + carray;
            if (digit >= 10) {
                digit -= 10;
                carray = 1;
            } else {
                carray = 0;
            }
            result.insert(result.begin(), digit + '0');
            it1++;
            it2++;
        }

        string::reverse_iterator it = it1, end = num1.rend();
        if (it2 != num2.rend()) {
            it = it2;
            end = num2.rend();
        }
        while (it != end) {
            digit = *it - '0' + carray;
            if (digit >= 10) {
                digit -= 10;
                carray = 1;
            } else {
                carray = 0;
            }
            result.insert(result.begin(), digit + '0');
            it++;
        }
        if (carray != 0) {
            result.insert(result.begin(), carray + '0');
        }
        return result;
    }
};

#ifdef LEETCODE
#include <iostream>
#include <cassert>
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.addStrings("1", "2") == "3");
    assert(s.addStrings("999", "1") == "1000");
    assert(s.addStrings("1", "999") == "1000");
    assert(s.addStrings("", "999") == "999");
    assert(s.addStrings("1111111111", "999999999") == "2111111110");
    return 0;
}
#endif
