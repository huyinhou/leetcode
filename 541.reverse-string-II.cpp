
#define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#endif

class Solution {
public:
    string reverseStr(string s, int k) {
        int pos = 0;
        for (; pos < s.size(); pos += 2 * k) {
            if (s.size() - pos < k) {
                std::reverse(s.begin() + pos, s.end());
            } else {
                std::reverse(s.begin() + pos, s.begin() + (pos + k));
            }
        }
        return s;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.reverseStr("abcdefg", 2) == "bacdfeg");
    assert(s.reverseStr("abcdefg", 3) == "cbadefg");
    return 0;
}
#endif
