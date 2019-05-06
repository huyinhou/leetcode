/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
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
#include <vector>
#include <numeric>
#include <map>
using namespace std;
#endif

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int, int> judge;   // judge => sum
        for (int i = 1; i <= N; i++) {
            judge[i] = 0;
        }
        for (auto it = trust.begin(); 
            !judge.empty() && it != trust.end(); 
            it++) {
            // cout<<it->at(0)<<" "<<it->at(1)<<std::endl;
            judge.erase(it->at(0));
            auto tmp = judge.find(it->at(1));
            if (tmp != judge.end()) {
                tmp->second += it->at(0);
                // cout<<tmp->first<<" "<<tmp->second<<std::endl;
            }
        }
        if (judge.empty()) {
            return -1;
        }
        int total = N * (N + 1) / 2;
        for (auto it = judge.begin(); it != judge.end(); it++) {
            // cout<<it->first<<" "<<it->second<<std::endl;
            if (total - it->first == it->second) {
                return it->first;
            }
        }
        return -1;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> t1={{1,2}};
    assert(s.findJudge(2, t1) == 2);
    vector<vector<int>> t2={{1,3},{2,3}};
    assert(s.findJudge(3, t2) == 3);
    vector<vector<int>> t3={{1,3},{2,3},{3,1}};
    assert(s.findJudge(3, t3) == -1);
    vector<vector<int>> t4={{1,2},{2,3}};
    assert(s.findJudge(3, t4) == -1);
    vector<vector<int>> t5={{1,3},{1,4},{2,3},{2,4},{4,3}};
    assert(s.findJudge(4, t5) == 3);
    return 0;
}
#endif

