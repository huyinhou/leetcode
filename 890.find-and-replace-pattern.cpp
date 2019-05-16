
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
#include <iterator>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#endif

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string newpat = formatPattern(pattern);
        vector<string> ret;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() != newpat.size()) {
                continue;
            }
            if (checkPattern(words[i], newpat)) {
                ret.push_back(words[i]);
            }
        }
        return ret;
    }

    string formatPattern(string &str) {
        string ret(str.size(), 'a');
        char cmap[26] = {0};
        char nextc = 'a';
        for (int i = 0; i < str.size(); i++) {
            char c = str[i] - 'a';
            if (cmap[c] == 0) {
                cmap[c] = nextc++;
            } 
            ret[i] = cmap[c];
        }
        return ret;
    }

    bool checkPattern(string &word, string &pat) {
        char cmap[26] = {0};
        char nextc = 'a';
        for (int i = 0; i < word.size(); i++) {
            char c = word[i] - 'a';
            if (cmap[c] == 0) {
                cmap[c] = nextc++;
            }
            if (pat[i] != cmap[c]) {
                return false;
            }
        }
        return true;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<string> v1 = {"abc","deq","mee","aqq","dkd","ccc","dd", "dgg"};
    auto ret = s.findAndReplacePattern(v1, "abb");
    std::copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, ", "));
    return 0;
}
#endif
