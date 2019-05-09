/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> map1;
        map<string, int> map2;
        for (int i = 0; i < list1.size(); i++) {
            map1[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); i++) {
            map2[list2[i]] = i;
        }
        int min_index_sum = INT_MAX;
        vector<string> ret;
        for (auto it = map1.begin(); it != map1.end(); it++) {
            auto it2 = map2.find(it->first);
            if (it2 != map2.end()) {
                int sum = it->second + it2->second;
                if (sum < min_index_sum) {
                    min_index_sum = sum;
                    ret.clear();
                    ret.push_back(it->first);
                } else if (sum == min_index_sum) {
                    ret.push_back(it->first);
                }
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<string> v1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> v2 = {"Piatti", "KFC", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    auto ret = s.findRestaurant(v1, v2);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, " "));

    return 0;
}
#endif

