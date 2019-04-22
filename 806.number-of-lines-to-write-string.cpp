/*
 * @lc app=leetcode id=806 lang=cpp
 *
 * [806] Number of Lines To Write String
 *
 * https://leetcode.com/problems/number-of-lines-to-write-string/description/
 *
 * algorithms
 * Easy (62.59%)
 * Total Accepted:    26.3K
 * Total Submissions: 41.9K
 * Testcase Example:  '[10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]\n"abcdefghijklmnopqrstuvwxyz"'
 *
 * We are to write the letters of a given string S, from left to right into
 * lines. Each line has maximum width 100 units, and if writing a letter would
 * cause the width of the line to exceed 100 units, it is written on the next
 * line. We are given an array widths, an array where widths[0] is the width of
 * 'a', widths[1] is the width of 'b', ..., and widths[25] is the width of
 * 'z'.
 * 
 * Now answer two questions: how many lines have at least one character from S,
 * and what is the width used by the last such line? Return your answer as an
 * integer list of length 2.
 * 
 * 
 * 
 * 
 * Example :
 * Input: 
 * widths =
 * [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
 * S = "abcdefghijklmnopqrstuvwxyz"
 * Output: [3, 60]
 * Explanation: 
 * All letters have the same length of 10. To write all 26 letters,
 * we need two full lines and one line with 60 units.
 * 
 * 
 * 
 * Example :
 * Input: 
 * widths =
 * [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
 * S = "bbbcccdddaaa"
 * Output: [2, 4]
 * Explanation: 
 * All letters except 'a' have the same length of 10, and 
 * "bbbcccdddaa" will cover 9 * 10 + 2 * 4 = 98 units.
 * For the last 'a', it is written on the second line because
 * there is only 2 units left in the first line.
 * So the answer is 2 lines, plus 4 units in the second line.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The length of S will be in the range [1, 1000].
 * S will only contain lowercase letters.
 * widths is an array of length 26.
 * widths[i] will be in the range of [2, 10].
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
using std::map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        size_t line = 0, count = 0;
        for (size_t i = 0; i < S.size(); i++) {
            size_t c = S[i] - 'a';
            if (count + widths[c] <= 100) {
                count += widths[c];
            } else {
                line++;
                count = widths[c];
            }
            // cout<<i<<" "<<line<<" "<<count<<std::endl;
        }
        if (count > 0) {
            line++;
        }
        vector<int> ret;
        ret.push_back(line);
        ret.push_back(count);
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> w1{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    auto ret = s.numberOfLines(w1, "abcdefghijklmnopqrstuvwxyz");
    assert(ret[0] == 3 && ret[1] == 60);

    vector<int> w2{4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    ret = s.numberOfLines(w2, "bbbcccdddaaa");
    cout<<ret[0]<<" "<<ret[1]<<std::endl;
    assert(ret[0] == 2 && ret[1] == 4);
    return 0;
}
#endif
