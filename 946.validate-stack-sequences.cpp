/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 *
 * https://leetcode.com/problems/validate-stack-sequences/description/
 *
 * algorithms
 * Medium (57.73%)
 * Total Accepted:    11.6K
 * Total Submissions: 20.1K
 * Testcase Example:  '[1,2,3,4,5]\n[4,5,3,2,1]'
 *
 * Given two sequences pushed and popped with distinct values, return true if
 * and only if this could have been the result of a sequence of push and pop
 * operations on an initially empty stack.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
 * Output: true
 * Explanation: We might do the following sequence:
 * push(1), push(2), push(3), push(4), pop() -> 4,
 * push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
 * Output: false
 * Explanation: 1 cannot be popped before 2.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= pushed.length == popped.length <= 1000
 * 0 <= pushed[i], popped[i] < 1000
 * pushed is a permutation of popped.
 * pushed and popped have distinct values.
 * 
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
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stack;
        size_t i = 0, j = 0;
        while ((i < pushed.size()) && (j < pushed.size())) {
            // cout<<i<<", "<<j<<std::endl;
            if (pushed[i] != popped[j]) {
                stack.push_back(pushed[i]);
            } else {
                j++;
                while ((j < pushed.size()) && (!stack.empty())) {
                    if (stack.back() != popped[j]) {
                        break;
                    }
                    stack.pop_back();
                    j++;
                }
            }
            i++;
        }
        return stack.empty() && (j == pushed.size());
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> pushed1{1, 2, 3, 4, 5};
    vector<int> poped1{4, 5, 3, 2, 1};
    assert(s.validateStackSequences(pushed1, poped1));
    vector<int> pushed2{1, 2, 3, 4, 5};
    vector<int> poped2{4, 3, 5, 1, 2};
    assert(!s.validateStackSequences(pushed2, poped2));
    
    return 0;
}
#endif
