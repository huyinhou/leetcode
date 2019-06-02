
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
public:
    bool isValid(string S) {
        size_t pos;
        while(!S.empty() && ((pos = S.find("abc")) != string::npos)) {
            S = S.erase(pos, 3);
        }
        return S.empty();
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.isValid("aabcbc"));
    assert(s.isValid("abcabcababcc"));
    assert(!s.isValid("abccba"));
    assert(!s.isValid("cababc"));
    return 0;
}
#endif
