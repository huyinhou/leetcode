
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
using namespace std;
#endif

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> s1;
        vector<char> s2;
        backspaceString(S, s1);
        backspaceString(T, s2);
        if (s1.size() != s2.size()) {
            return false;
        }
        for (size_t i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }
        return true;
    }

    void backspaceString(string &s, vector<char> &ret) {
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (!ret.empty()) {
                    ret.pop_back();
                }
            } else {
                ret.push_back(s[i]);
            }
        }
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.backspaceCompare("ab#c", "ad#c"));
    assert(s.backspaceCompare("ab##", "c#d#"));
    assert(s.backspaceCompare("a##c", "#a#c"));
    assert(!s.backspaceCompare("a#c", "b"));
    assert(s.backspaceCompare("y#fo##f", "y#f#o##f"));
    return 0;
}
#endif
