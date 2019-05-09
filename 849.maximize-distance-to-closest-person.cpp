/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
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
#include <algorithm>
#include <map>
using namespace std;
#endif

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max_dist = 0;
        int last_persion = -1;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                if (last_persion < 0) {
                    max_dist = 2 * i;
                } else if (i - last_persion > max_dist) {
                    max_dist = i - last_persion;
                }
                last_persion = i;
            }
        }
        int last_dist = 2 * (seats.size() - last_persion - 1);
        if (last_dist > max_dist) {
            max_dist = last_dist;
        }
        return max_dist / 2;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,0,0,0,1,0,1};
    assert(s.maxDistToClosest(v1) == 2);
    vector<int> v2 = {1,0,0,0};
    assert(s.maxDistToClosest(v2) == 3);
    vector<int> v3 = {0,0,0,0,1};
    assert(s.maxDistToClosest(v3) == 4);
    vector<int> v4 = {0,1,1,1,0,0,1,0,0};
    assert(s.maxDistToClosest(v4) == 2);
    return 0;
}
#endif

