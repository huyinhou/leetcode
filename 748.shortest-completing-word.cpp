/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
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
void dumpArray(short a[26]) {
    for (size_t i = 0; i < 26; i++) {
        cout<<a[i]<<" ";
    }
    cout<<std::endl;
}
#endif

class Solution {
public:
    struct IndexCount {
        IndexCount(short i, short c): idx(i), cnt(c) { }
        short idx;
        short cnt;
    };

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        short count[26];
        memset(count, 0, sizeof(count));
        vector<IndexCount> license;
        for (size_t i = 0; i < licensePlate.size(); i++) {
            if (isalpha(licensePlate[i])) {
                count[tolower(licensePlate[i]) - 'a']++;
            }
        }
        // dumpArray(count);
        for (size_t i = 0; i < 26; i++) {
            if (!count[i]) {
                continue;
            }
            license.push_back(IndexCount(i, count[i]));
        }
        string ret;
        for (size_t i = 0; i < words.size(); i++) {
            string &w = words[i];
            memset(count, 0, sizeof(count));
            if (!ret.empty() && w.size() >= ret.size()) {
                continue;
            }
            for (size_t j = 0; j < w.size(); j++) {
                count[w[j] - 'a']++;
            }
            // dumpArray(count);
            auto it = license.begin();
            while (it != license.end()) {
                if (count[it->idx] < it->cnt) {
                    break;
                }
                it++;
            }
            if (it == license.end()) {
                ret = w;
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<string> v1{
        "step", "steps", "stripe", "stepple"
    };
    assert(s.shortestCompletingWord("1s3 PSt", v1) == "steps");

    vector<string> v2{
        "looks", "pest", "stew", "show"
    };
    assert(s.shortestCompletingWord("1s3 456", v2) == "pest");
    return 0;
}
#endif
