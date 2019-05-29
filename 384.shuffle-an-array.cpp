
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
#include <random>
using namespace std;
#endif

class Solution {
public:
    Solution(vector<int>& nums) {
        data.assign(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> temp(data);
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(temp.begin(), temp.end(), g);
        return temp;
    }

private:
    vector<int> data;
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    
    vector<int> v1 = {1,2,3,4,5,6};
    Solution s(v1);
    auto ret = s.reset();
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout<<std::endl;

    ret = s.shuffle();
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout<<std::endl;

    ret = s.shuffle();
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
