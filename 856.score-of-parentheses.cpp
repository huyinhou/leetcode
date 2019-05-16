
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
    int scoreOfParentheses(string S) {
        int flag = 1;
        int count = 0;
        char prev = '(';
        for (int i = 1; i < S.size(); i++) {
            char c = S[i];
            if (c == ')') {
                if (prev == '(') {
                    count += flag;   
                }
                flag >>= 1;
            } else {
                if (flag == 0) {
                    flag = 1;
                } else {
                    flag <<= 1;
                }
            }
            prev = c;
        }
        return count;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.scoreOfParentheses("()") == 1);
    assert(s.scoreOfParentheses("()()") == 2);
    assert(s.scoreOfParentheses("(()(()))") == 6);
    assert(s.scoreOfParentheses("(()(()))()()") == 8);
    return 0;
}
#endif
