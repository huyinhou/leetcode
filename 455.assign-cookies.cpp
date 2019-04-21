/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 *
 * https://leetcode.com/problems/assign-cookies/description/
 *
 * algorithms
 * Easy (48.09%)
 * Total Accepted:    60.7K
 * Total Submissions: 125.9K
 * Testcase Example:  '[1,2,3]\n[1,1]'
 *
 * 
 * Assume you are an awesome parent and want to give your children some
 * cookies. But, you should give each child at most one cookie. Each child i
 * has a greed factor gi, which is the minimum size of a cookie that the child
 * will be content with; and each cookie j has a size sj. If sj >= gi, we can
 * assign the cookie j to the child i, and the child i will be content. Your
 * goal is to maximize the number of your content children and output the
 * maximum number.
 * 
 * 
 * Note:
 * You may assume the greed factor is always positive. 
 * You cannot assign more than one cookie to one child.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3], [1,1]
 * 
 * Output: 1
 * 
 * Explanation: You have 3 children and 2 cookies. The greed factors of 3
 * children are 1, 2, 3. 
 * And even though you have 2 cookies, since their size is both 1, you could
 * only make the child whose greed factor is 1 content.
 * You need to output 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2], [1,2,3]
 * 
 * Output: 2
 * 
 * Explanation: You have 2 children and 3 cookies. The greed factors of 2
 * children are 1, 2. 
 * You have 3 cookies and their sizes are big enough to gratify all of the
 * children, 
 * You need to output 2.
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

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // std::copy(g.begin(), g.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        size_t si = 0;
        size_t gi = 0;
        while (gi < g.size()) {
            while (si < s.size()) {
                // cout<<si<<", "<<gi<<", "<<s[si]<<", "<<g[gi]<<std::endl;
                if (s[si] >= g[gi]) {
                    gi++;
                    si++;
                    break;
                }
                si++;
            }
            if (si == s.size()) {
                break;
            }
        }
        return gi;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    int g1[] = {3, 2, 1};
    int s1[] = {1, 1};
    vector<int> vg1(g1, g1 + sizeof(g1) / sizeof(int));
    vector<int> vs1(s1, s1 + sizeof(s1) / sizeof(int));
    assert(s.findContentChildren(vg1, vs1) == 1);
    int g2[] = {3, 2, 1};
    int s2[] = {3};
    vector<int> vg2(g2, g2 + sizeof(g2) / sizeof(int));
    vector<int> vs2(s2, s2 + sizeof(s2) / sizeof(int));
    assert(s.findContentChildren(vg2, vs2) == 1);
    return 0;
}
#endif
