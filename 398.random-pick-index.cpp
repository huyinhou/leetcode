
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
    Solution(vector<int>& nums): data(nums) {
        srand(time(nullptr));
    }
    
    int pick(int target) {
        int index = 0;
        int count = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] != target) {
                continue;
            }
            if (rand() % (++count) == 0) {
                index = i;
            }
        }
        return index;
    }

private:
    vector<int> &data;
};

int main(int argc, char *argv[]) {
    vector<int> v1 = {1,2,3,3,3};
    Solution s(v1);
    for (int i = 0; i < 10; i++) {
        cout<<s.pick(3)<<std::endl;
    }
    return 0;
}
#endif
