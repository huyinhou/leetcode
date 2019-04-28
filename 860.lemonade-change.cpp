/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
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
    bool lemonadeChange(vector<int>& bills) {
        vector<int> charge(4);
        for (size_t i = 0; i < bills.size(); i++) {
            // std::copy(charge.begin(), charge.end(), std::ostream_iterator<int>(cout, ", "));
            // cout<<std::endl;
            int b = bills[i], r = b - 5;
            if (r  == 0) {
                charge[0]++;
                continue;
            }
            if (r >= 10 && charge[1]) {
                r -= 10;
                charge[1]--;
            }
            r /= 5;
            if (charge[0] >=  r ) {
                charge[0] -= r;
            } else {
                return false;
            }
            charge[b / 5 - 1]++;
        }
        return true;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> b1{5,5,5,10,20};
    assert(s.lemonadeChange(b1));
    cout<<std::endl;
    vector<int> b2{5,5,10};
    assert(s.lemonadeChange(b2));
    cout<<std::endl;
    vector<int> b3{10,10};
    assert(!s.lemonadeChange(b3));
    cout<<std::endl;
    vector<int> b4{5,5,10,10,20};
    assert(!s.lemonadeChange(b4));
    cout<<std::endl;
    return 0;
}
#endif
