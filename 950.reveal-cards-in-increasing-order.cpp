
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
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        std::sort(deck.begin(), deck.end(), greater<int>());
        vector<int> order;
        for (size_t i = 0; i < deck.size(); i++) {
            if (!order.empty()) {
                order.push_back(order.front());
                order.erase(order.begin());
            }
            order.push_back(deck[i]);
        }
        std::reverse(order.begin(), order.end());
        return order;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {17,13,11,2,3,5,7};
    auto ret = s.deckRevealedIncreasing(v1);
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
