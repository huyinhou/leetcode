/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (41.71%)
 * Total Accepted:    45.4K
 * Total Submissions: 108.6K
 * Testcase Example:  '26'
 *
 * 
 * Given an integer, write an algorithm to convert it to hexadecimal. For
 * negative integer, two’s complement method is used.
 * 
 * 
 * Note:
 * 
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is
 * zero, it is represented by a single zero character '0'; otherwise, the first
 * character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You must not use any method provided by the library which converts/formats
 * the number to hex directly.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 26
 * 
 * Output:
 * "1a"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * -1
 * 
 * Output:
 * "ffffffff"
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cstddef>
#include <cstdio>
#include <string>
using std::string;
#endif

class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }

        uint32_t tmp = static_cast<uint32_t>(num);
        uint32_t lmask = 0xf, hmask = 0xf0;
        char digits[3] = {0};
        string result;
        while (tmp != 0) {
            uint8_t c = tmp & 0xff;
            digits[0] = hexdigits[(c & 0xf0)>>4];
            digits[1] = hexdigits[(c & 0xf)];
            result.insert(0, digits);
            tmp>>=8;
        }
        size_t off = 0;
        while (result[off] == '0' && off < result.length()) {
            off++;
        }
        result.erase(result.begin(), result.begin() + off);
        return result;
    }

private:
    static char hexdigits[16];
};

char Solution::hexdigits[16] = {
    '0', '1', '2', '3', 
    '4', '5', '6', '7', 
    '8', '9', 'a', 'b', 
    'c', 'd', 'e', 'f'};


#ifdef LEETCODE
#include <iostream>
#include <cassert>
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.toHex(1) == "1");
    assert(s.toHex(10) == "a");
    assert(s.toHex(0) == "0");
    std::cout<<s.toHex(-1);
    assert(s.toHex(-1) == "ffffffff");
    // assert()
    return 0;
}
#endif


