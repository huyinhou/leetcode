
#define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#endif

class Solution {
    static const char *units[4][10];

public:
    string intToRoman(int num) {
        int index = 3;
        int temp = 1000;
        string ret;
        while (num > 0) {
            ret.append(units[index][num / temp]);
            num = num % temp;
            temp = temp / 10;
            index--;
        }
        return ret;
    }
};

const char *Solution::units[4][10] = {
    {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
    {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
    {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
    {"", "M", "MM", "MMM", nullptr}
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.intToRoman(58) == "LVIII");
    assert(s.intToRoman(1994) == "MCMXCIV");
    return 0;
}
#endif
