/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
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
    vector<string> uncommonFromSentences(string A, string B) {
        map<string, int> worda;
        map<string, int> wordb;
        splitString(A, worda);
        splitString(B, wordb);
        vector<string> ret;
        exceptKeys(worda, wordb, ret);
        exceptKeys(wordb, worda, ret);
        return ret;
    }

    void splitString(string &str, map<string, int> &wordmap) {
        size_t idx = 0;
        while (idx < str.size()) {
            size_t pos = str.find_first_of(' ', idx);
            if (pos != idx) {
                if (pos == string::npos) {
                    string w(str, idx);
                    wordmap[w]++;
                    break;
                } else {
                    string w(str, idx, pos - idx);
                    wordmap[w]++;
                }
            }
            idx = pos +1;
        }
    }

    void exceptKeys(map<string, int> &worda, map<string, int> &wordb, vector<string> &keys) {
        for (auto it = worda.begin(); it != worda.end(); it++) {
            if (it->second > 1) {   // 只出现一次
                continue;
            }
            if (wordb.find(it->first) == wordb.end()) { // 不在另外一个集合
                keys.push_back(it->first);
            }
        }
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    auto ret = s.uncommonFromSentences("this apple is sweet", "this apple is  sour");
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, ", "));
    cout<<std::endl;
    ret = s.uncommonFromSentences("apple apple", "bannna   ");
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
