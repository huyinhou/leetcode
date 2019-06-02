
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

class CustComp {
public:
    CustComp(const string &s) {
        for (int i = 0; i < 26; i++) {
            order[i] = 26;
        }
        for (int i = 0; i < s.size(); i++) {
            order[s[i] - 'a'] = i;
        }
    }

    bool operator()(char c1, char c2) {
        return order[c1 - 'a'] < order[c2 - 'a'];
    }

private:
    int order[26];
};

class Solution {
public:
    string customSortString(string S, string T) {
        std::sort(T.begin(), T.end(), CustComp(S));
        return T;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    auto ret = s.customSortString("cba", "abcd");
    cout<<ret<<std::endl;
    ret = s.customSortString("cba", "abcdabc");
    cout<<ret<<std::endl;
    return 0;
}
#endif
