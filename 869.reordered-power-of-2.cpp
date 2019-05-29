
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
#include <set>
using namespace std;
#endif

class Solution {
public:
    Solution() {
        for (int i = 0; i < 31; i++) {
            dset.insert(numDigits(1 << i));
        }
    }

    bool reorderedPowerOf2(int N) {
        auto it = dset.find(numDigits(N));
        return it != dset.end();
    }

    uint32_t numDigits(int n) {
        int digits[10] = {0};
        while (n > 0) {
            digits[n % 10]++;
            n /= 10;
        }
        uint32_t d = 0;
        for (int i = 9; i >= 0; i--) {
            d = d * 10 + digits[i];
        }
        return d;
    }

private:
    set<uint32_t> dset;
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.numDigits(1) == 10);
    // cout<<s.numDigits(20);
    assert(s.numDigits(20) == 101);
    assert(s.numDigits(1000) == 13);
    assert(s.reorderedPowerOf2(1));
    assert(!s.reorderedPowerOf2(10));
    assert(s.reorderedPowerOf2(16));
    assert(!s.reorderedPowerOf2(24));
    assert(s.reorderedPowerOf2(46));
    return 0;
}
#endif
