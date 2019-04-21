
#define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <sstream>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

class Solution {
public:
    string removeOuterParentheses(string s) {
        ostringstream oss;
        int stack = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack++;
                if (stack == 1) {
                    continue;
                }
            } else {
                stack--;
                if (stack == 0) {
                    continue;
                }
            }
            oss<<s[i];
        }
        return oss.str();
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.removeOuterParentheses("(()())(())") == "()()()");
    assert(s.removeOuterParentheses("(()())(())(()(()))") == "()()()()(())");
    assert(s.removeOuterParentheses("()()") == "");
    assert(s.removeOuterParentheses("") == "");
    return 0;
}
#endif
