/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
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
#include <numeric>
#include <functional>
using namespace std;
#endif

class Solution {
public:
    class greater_than : std::unary_function<char, bool> {
    public:
        explicit greater_than(char t) : target(t) {}
        bool operator()(argument_type __x) const {
            return __x > target;
        }

    private:
        char target;
    };

    char nextGreatestLetter(vector<char>& letters, char target) {
        auto cmp = std::greater<char>();
        auto it = std::find_if(letters.begin(), letters.end(), greater_than(target));
        if (it == letters.end()) {
            return letters[0];
        }
        return *it;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<char> c1 = {'c', 'f', 'j'};
    assert(s.nextGreatestLetter(c1, 'a') == 'c');
    assert(s.nextGreatestLetter(c1, 'c') == 'f');
    assert(s.nextGreatestLetter(c1, 'd') == 'f');
    assert(s.nextGreatestLetter(c1, 'g') == 'j');
    assert(s.nextGreatestLetter(c1, 'j') == 'c');
    return 0;
}
#endif

