
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
    vector<vector<int>> combinationSum3(int k, int n) {
        return combinationSum(k, n, 9);
    }

    vector<vector<int>> combinationSum(int k, int n, int d) {
        vector<vector<int>> ret;
        if (k < 0) {
            return ret;
        } else if (k == 1) {
            if (n <= d) {
                ret.push_back(vector<int>{n});
            }
            return ret;
        } else if (k == 2) {
            int i = 1, j = d;
            while (i < j) {
                if (i + j < n) {
                    i++;
                } else if (i + j == n) {
                    ret.push_back(vector<int>{i, j});
                    i++;
                    j--;
                } else {
                    j--;
                }
            }
            return ret;
        }

        // k >= 3
        int sum = k * (k - 1) / 2;
        if (k > d || n < sum + k) {
            return ret;
        }
        for (int c = static_cast<int>(std::ceil((n + sum) / k)); c <= std::min(n - sum, d); c++) {
            auto temp = combinationSum(k - 1, n - c, c - 1);
            for (auto v : temp) {
                v.push_back(c);
                ret.push_back(v);
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
void dump(vector<vector<int>> &ret) {
    cout<<"[";
    for (auto v : ret) {
        cout<<"[";
        for (auto i : v) {
            cout<<i<<", ";
        }
        cout<<"], ";
    }
    cout<<"]"<<std::endl;
}

int main(int argc, char *argv[]) {
    Solution s;
    auto ret = s.combinationSum3(3, 7);
    dump(ret);
    ret = s.combinationSum3(3, 9);
    dump(ret);
    ret = s.combinationSum3(3, 12);
    dump(ret);
    ret = s.combinationSum3(4, 15);
    dump(ret);
    ret = s.combinationSum3(3, 2);
    dump(ret);
    ret = s.combinationSum3(3, 28);
    dump(ret);

    ret = s.combinationSum3(4, 24);
    dump(ret);
    return 0;
}
#endif
