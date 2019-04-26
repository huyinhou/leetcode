/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
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
#include <map>
#include <vector>
using namespace std;
#endif

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<int> index;
        for (size_t i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                index.push_back(i);
            }
        }
        vector<string> ret;
        size_t maxf = (1 << index.size());
        for (size_t flag = 0; flag < maxf; flag++) {
            size_t mask = 1;
            for (auto it = index.begin(); it != index.end(); it++, mask <<= 1) {
                if (mask & flag) {  // 为1
                    s[*it] = toupper(s[*it]);
                } else {
                    s[*it] = tolower(s[*it]);
                }
            }
            ret.push_back(s);
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    auto ret = s.letterCasePermutation("a123b");
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, ", "));
    cout<<std::endl;
    ret = s.letterCasePermutation("1a2b3b5c");
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, ", "));
    cout<<std::endl;
    ret = s.letterCasePermutation("123456");
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
