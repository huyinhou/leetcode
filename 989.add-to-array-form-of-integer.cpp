
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
#include <stack>
#include <algorithm>
using namespace std;
#endif


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        vector<int> b;
        while (k > 0) {
            b.push_back(k % 10);
            k /= 10;
        }
        std::reverse(b.begin(), b.end());
        vector<int> c;
        int carry = 0;
        auto ia = a.rbegin(), ib = b.rbegin();
        while (ia != a.rend() || ib != b.rend()) {
            int num = carry;
            if (ia != a.rend()) {
                num += *ia;
                ia++;
            }
            if (ib != b.rend()) {
                num += *ib;
                ib++;
            }
            if (num >= 10) {
                num -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            c.push_back(num);
        }
        if (carry) {
            c.push_back(carry);
        }
        std::reverse(c.begin(), c.end());
        return c;
    }
};


#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {2,7,4};
    auto ret = s.addToArrayForm(v1, 181);
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout<<std::endl;

    vector<int> v2 = {2,1,5};
    ret = s.addToArrayForm(v2, 806);
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
