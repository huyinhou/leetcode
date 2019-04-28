/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
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
#include <cmath>
using namespace std;
#endif

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        map<unsigned, int> tmp;
        int total  = 0;
        for (size_t i = 0; i < points.size(); i++) {
            for (size_t j = 0; j < points.size(); j++) {
                if (i == j) {
                    continue;
                }

                vector<int> &pi = points[i];
                vector<int> &pj = points[j];
                unsigned dist = static_cast<unsigned>(
                    pow(pi[0] - pj[0], 2) + pow(pi[1] - pj[1], 2));
                tmp[dist]++;
            }

            for (auto it = tmp.begin(); it != tmp.end(); it++) {
                total += it->second * (it->second - 1);
            }
            tmp.clear();
        }
        return total;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v1 = {
        {0,0},
        {1,0},
        {2,0}
    };
    assert(s.numberOfBoomerangs(v1) == 2);
    return 0;
}
#endif

