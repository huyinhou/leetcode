
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
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
#endif

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sumw = 0, maxw = 0;
        std::for_each(weights.begin(), weights.end(), [&sumw, &maxw](int w) {
            sumw += w;
            maxw = std::max(maxw, w);
        });
        maxw = std::max(maxw, static_cast<int>(std::ceil(sumw * 1.0 / D)));
        while (maxw <= sumw) {
            int days = 0;
            int temp = 0;
            for (size_t i = 0; i < weights.size(); i++) {
                if (temp + weights[i] < maxw) {
                    temp += weights[i];
                    continue;
                } else if (temp + weights[i] == maxw) {
                    days++;
                    temp = 0;
                } else {
                    days++;
                    temp = weights[i];
                }
            }
            if (temp > 0) {
                days++;
            }
            if (days <= D) {
                break;
            }
            maxw++;
        }
        return maxw;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    assert(s.shipWithinDays(v1, 5) == 15);
    return 0;
}
#endif
