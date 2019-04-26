/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Log Files
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
    vector<string> reorderLogFiles(vector<string>& logs) {
        std::stable_sort(logs.begin(), logs.end(), Solution::logCompare);
        return logs;
    }

    static bool logCompare(const string &log1, const string &log2) {
        auto pos1 = log1.find_first_of(' ', 0) + 1;
        auto pos2 = log2.find_first_of(' ', 0) + 1;
        if (log1[pos1] >= 'a') {
            if (log2[pos2] >= 'a') {
                int ret = strcmp(&log1[pos1], &log2[pos2]);
                if (ret == 0) {
                    ret = strncmp(log1.c_str(), log2.c_str(), 
                        (pos1 > pos2 ? pos2 : pos1));
                }
                return ret < 0;
            }
            return true;
        }
        return false;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<string> logs = {
        "a1 9 2 3 1",
        "g1 act car",
        "zo4 4 7",
        "ab1 off key dog",
        "a8 act zoo",
        "a2 act car"
    };
    auto ret = s.reorderLogFiles(logs);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif

