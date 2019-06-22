
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



#ifdef LEETCODE
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = 0;
        while (i < arr.size()) {
            if (arr[i] != 0) {
                i++;
                continue;
            }
            for (int j = arr.size() - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            i += 2;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,0,2,3,0,4,5,0};
    s.duplicateZeros(v1);
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(cout, ", "));
    return 0;
}
#endif
