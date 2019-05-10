
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
#include <queue>
using namespace std;
#endif

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0;
        vector<bool> ret(A.size(), false);
        for (size_t i = 0; i < A.size(); i++) {
            num = (num << 1) | A[i];
            num %= 5;   // 这里要注意，把已经整除5的部分剔除掉，防止溢出
            if (num == 0) {
                ret[i] = true;
                num = 0;
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {0,1,1};
    auto ret = s.prefixesDivBy5(v1);
    std::copy(ret.begin(), ret.end(), ostream_iterator<bool>(cout, ", "));
    cout<<endl;
    vector<int> v2 = {1,1,1};
    ret = s.prefixesDivBy5(v2);
    std::copy(ret.begin(), ret.end(), ostream_iterator<bool>(cout, ", "));
    cout<<endl;
    vector<int> v3 = {1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,1};
    ret = s.prefixesDivBy5(v3);
    std::copy(ret.begin(), ret.end(), ostream_iterator<bool>(cout, ", "));
    cout<<endl;
    vector<int> v4 = {1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,1,0,1,1,1,0,0,1,0};
    ret = s.prefixesDivBy5(v4);
    std::copy(ret.begin(), ret.end(), ostream_iterator<bool>(cout, ", "));
    cout<<endl;
    return 0;
}
#endif


