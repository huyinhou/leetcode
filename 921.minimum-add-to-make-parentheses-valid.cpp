
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
    int minAddToMakeValid(string S) {
        int leftp = 0;
        int count = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                leftp++;
            } else if (S[i] == ')') {
                if (leftp == 0) {
                    count++;
                } else {
                    leftp--;
                }
            }
        }
        return count + leftp;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.minAddToMakeValid("())") == 1);
    assert(s.minAddToMakeValid("(((") == 3);
    assert(s.minAddToMakeValid("()") == 0);
    assert(s.minAddToMakeValid("()))((") == 4);
    return 0;
}
#endif
