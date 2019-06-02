
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
using namespace std;
#endif

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (W == 1) {
            return true;
        }
        if (hand.size() % W != 0) {
            return false;
        }
        std::sort(hand.begin(), hand.end());
        while (!hand.empty()) {
            int last = hand.back();
            hand.pop_back();
            int w = W;
            int i = hand.size() - 1;
            while (--w >= 1) {
                last--;
                bool got = false;
                while (i >= 0) {
                    if (last < hand[i]) {
                        i--;
                    } else if (last == hand[i]) {
                        hand.erase(hand.begin() + i);
                        got = true;
                        i--;
                        break;
                    } else {
                        return false;
                    }
                }
                if (!got) {
                    return false;
                }
            }
        }
        return true;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,2,3,6,2,3,4,7,8};
    assert(s.isNStraightHand(v1, 3));
    vector<int> v2 = {1,2,3,4,5};
    assert(!s.isNStraightHand(v2, 4));
    vector<int> v3 = {0,1};
    assert(s.isNStraightHand(v3, 2));
    vector<int> v4 = {5,1};
    assert(!s.isNStraightHand(v4, 2));
    vector<int> v5 = {1,1,2,2,3,3};
    assert(!s.isNStraightHand(v5, 2));
    return 0;
}
#endif
