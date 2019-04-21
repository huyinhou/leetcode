/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (47.96%)
 * Total Accepted:    40.9K
 * Total Submissions: 85.1K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
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

#include <algorithm>

class RankComp {
public:
    RankComp(vector<int> &s) : score(s) {

    }

    bool operator() (int i,int j) { 
        return (score[i]>score[j]);
    }

private:
    vector<int> &score;
};
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> order(nums.size());
        for (size_t i = 0; i < order.size(); i++) {
            order[i] = i;
        }
        RankComp cmp(nums);
        std::sort(order.begin(), order.end(), cmp);
        vector<string> ret(nums.size());
        char buf[12] = "";
        for (size_t i = 0; i < order.size(); i++) {
            if (i == 0) {
                ret[order[i]] = "Gold Medal";
            } else if (i == 1) {
                ret[order[i]] = "Silver Medal";
            } else if (i == 2) {
                ret[order[i]] = "Bronze Medal";
            } else {
                sprintf(buf, "%lu", i + 1);
                ret[order[i]] = buf;
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    int n1[] = {5, 4, 3, 2, 1};
    vector<int> v1(n1, n1 + sizeof(n1) / sizeof(int));
    auto ret = s.findRelativeRanks(v1);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(std::cout, ", "));
    cout<<std::endl;
    int n2[] = {1, 2};
    vector<int> v2(n2, n2 + sizeof(n2) / sizeof(int));
    ret = s.findRelativeRanks(v2);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(std::cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
