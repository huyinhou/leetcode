/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;
#endif

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j = 0;
        for (int i = 0; i < name.size(); i++) {
            if (name[i] != typed[j++]) {
                return false;
            }
            if (i + 1 < name.size() && name[i] == name[i + 1]) {    // 匹配一个字符
                continue;
            } else { // 匹配任意多字符
                while (j < typed.size()) {
                    if (name[i] != typed[j]) {
                        break;
                    }
                    j++;
                }
            }
        }
        return true;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.isLongPressedName("alex", "aaleex"));
    assert(!s.isLongPressedName("saeed", "ssaaedd"));
    assert(s.isLongPressedName("leelee", "lleeelee"));
    assert(!s.isLongPressedName("leeeelee", "lleeelee"));
    assert(s.isLongPressedName("laiden", "laiden"));
    assert(!s.isLongPressedName("xnhtq", "xhhttqq"));
    return 0;
}
#endif

