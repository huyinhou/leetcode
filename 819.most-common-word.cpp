/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cctype>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <functional>   // std::bind
#include <map>
using namespace std;
#endif


bool is_alpha_(char ch) {
    return isalpha(ch);
}

bool not_alpha_(char ch) {
    return !isalpha(ch);
}

char to_lower_(char ch) {
    return tolower(ch);
}

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> banset;
        for (auto it = banned.begin(); it != banned.end(); it++) {
            banset.insert(*it);
        }
        map<string, int> wordcnt;
        auto it = paragraph.begin();
        while (it != paragraph.end()) {
            auto pos = std::find_if(it, paragraph.end(), is_alpha_);
            if (pos == paragraph.end()) {
                break;
            }
            auto end = std::find_if(pos, paragraph.end(), not_alpha_);
            string str = paragraph.substr(pos - paragraph.begin(), end - pos);
            std::transform(str.begin(), str.end(), str.begin(), to_lower_);
            it = end;
            if (banset.find(str) != banset.end()) {
                continue;
            }
            wordcnt[str]++;
        }
        int maxcnt = 0;
        string ret;
        for (auto it = wordcnt.begin(); it != wordcnt.end(); it++) {
            if (maxcnt < it->second) {
                ret = it->first;
                maxcnt = it->second;
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<string> b1 = {
        "hit"
    };
    assert(s.mostCommonWord("Bob hit a ball, the hit hit BALL flew far after it was hit.", b1) == "ball");
    return 0;
}
#endif

