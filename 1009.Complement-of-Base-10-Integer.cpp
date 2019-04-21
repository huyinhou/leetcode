
#define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) {
            return 1;
        }
        unsigned mask = 1 << 31;
        unsigned num = N;
        num = ~num;
        // 去除高位的1
        while (mask != 0) {
            if (mask & num) {
                num &= ~mask;
            } else {
                break;
            }
            mask >>= 1;
        }
        return num;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.bitwiseComplement(0) == 1);
    assert(s.bitwiseComplement(5) == 2);
    assert(s.bitwiseComplement(7) == 0);
    assert(s.bitwiseComplement(10) == 5);
    return 0;
}
#endif
