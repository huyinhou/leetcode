/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
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
    bool isAlienSorted(vector<string>& words, string order) {
        char letters[128] = {0};
        for (size_t i = 0; i < order.size(); i++) {
            letters[order[i]] = static_cast<char>('a' + i);
        }
        for (size_t i = 1; i < words.size(); i++) {
            string &a0 = words[i - 1];
            string &a1 = words[i];
            size_t j = 0;
            for (; (j < a0.size()) && (j < a1.size()); j++) {
                char c0 = letters[a0[j]], c1 = letters[a1[j]];
                if (c0 < c1) {
                    break;
                } else if (c0 > c1) {
                    return false;
                }
            }
            if (j < a0.size() && j == a1.size()) {
                return false;
            }
        }
        return true;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<string> w1 = {
        "hello",
        "leetcode"
    };
    assert(s.isAlienSorted(w1, "hlabcdefgijkmnopqrstuvwxyz"));
    vector<string> w2 = {
        "word",
        "world",
        "row"
    };
    assert(!s.isAlienSorted(w2, "worldabcefghijkmnpqstuvxyz"));
    return 0;
}
#endif

