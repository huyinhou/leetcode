
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
    string removeDuplicates(string S) {
        int i = 0, j = 0;
        while (j < S.size()) {
            if (i == 0) {
                S[i++] = S[j];
            } else if (S[i - 1] == S[j]) {
                i--;
            } else {
                S[i++] = S[j];
            }
            j++;
        }
        S.resize(i);
        return S;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.removeDuplicates("abbaca") == "ca");
    assert(s.removeDuplicates("abcddcbadd") == "");
    return 0;
}
#endif
