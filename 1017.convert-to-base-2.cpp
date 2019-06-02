
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
    string baseNeg2(int N) {
        if (N == 0) {
            return "0";
        }

        string ret;
        while(N != 0) {
            int d = N % 2;
            if (N < 0) {
                d = -d;
                N = (N - 1) / -2;
            } else {
                N = N / -2;
            }
            ret.push_back('0' + d);
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    cout<<3/-2<<", "<< -3/2<<std::endl;
    cout<<3 % -2<<", "<<-3 % 2<<", "<<-3 % -2<<std::endl;
    cout<<s.baseNeg2(1)<<std::endl;
    cout<<s.baseNeg2(2)<<std::endl;
    cout<<s.baseNeg2(3)<<std::endl;
    cout<<s.baseNeg2(4)<<std::endl;
    return 0;
}
#endif
