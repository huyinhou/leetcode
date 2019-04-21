/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 *
 * https://leetcode.com/problems/string-compression/description/
 *
 * algorithms
 * Easy (36.98%)
 * Total Accepted:    47K
 * Total Submissions: 126.2K
 * Testcase Example:  '["a","a","b","b","c","c","c"]'
 *
 * Given an array of characters, compress it in-place.
 * 
 * The length after compression must always be smaller than or equal to the
 * original array.
 * 
 * Every element of the array should be a character (not int) of length 1.
 * 
 * After you are done modifying the input array in-place, return the new length
 * of the array.
 * 
 * 
 * Follow up:
 * Could you solve it using only O(1) extra space?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ["a","a","b","b","c","c","c"]
 * 
 * Output:
 * Return 6, and the first 6 characters of the input array should be:
 * ["a","2","b","2","c","3"]
 * 
 * Explanation:
 * "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by
 * "c3".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ["a"]
 * 
 * Output:
 * Return 1, and the first 1 characters of the input array should be: ["a"]
 * 
 * Explanation:
 * Nothing is replaced.
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 * 
 * Output:
 * Return 4, and the first 4 characters of the input array should be:
 * ["a","b","1","2"].
 * 
 * Explanation:
 * Since the character "a" does not repeat, it is not compressed.
 * "bbbbbbbbbbbb" is replaced by "b12".
 * Notice each digit has it's own entry in the array.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All characters have an ASCII value in [35, 126].
 * 1 <= len(chars) <= 1000.
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

class Solution {
public:
    int compress(vector<char>& chars) {
        char c = 0;
        size_t next = 0;
        int count = 0;
        for (size_t i = 0; i < chars.size(); i++) {
            if (c == 0 || c != chars[i]) {
                if (count > 1) {
                    chars[next++] = c;
                    next += fillCount(&chars[next], count);
                } else if (count == 1) {
                    chars[next++] = c;
                }
                c = chars[i];
                count = 1;
            } else {
                count++;
            }
        }
        if (count > 1) {
            chars[next++] = c;
            next += fillCount(&chars[next], count);
        } else if (count == 1) {
            chars[next++] = c;
        }
        return next;
    }

    int fillCount(char *p, int n) {
        if (n < 10) {
            *p = n + '0';
            return 1;
        }
        return sprintf(p, "%d", n);
    }
};

#ifdef LEETCODE
vector<char> buildVector(string s) {
    vector<char> ret;
    for (size_t i = 0; i < s.length(); i++) {
        ret.push_back(s[i]);
    }
    return ret;
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<char> c1 = buildVector("a");
    assert(s.compress(c1) == 1);
    c1 = buildVector("aaaabccc");
    assert(s.compress(c1) == 5);
    std::copy(c1.begin(), c1.begin() + 5, std::ostream_iterator<char>(std::cout, ", "));
    cout<<std::endl;
    c1 = buildVector("bbbbbbbbbbbb");
    assert(s.compress(c1) == 3);
    std::copy(c1.begin(), c1.begin() + 3, std::ostream_iterator<char>(std::cout, ", "));
    cout<<std::endl;
    c1 = buildVector("aa");
    assert(s.compress(c1) == 2);
    std::copy(c1.begin(), c1.end(), std::ostream_iterator<char>(std::cout, ", "));
    cout<<std::endl;
    c1 = buildVector("aaaaab");
    assert(s.compress(c1) == 3);
    std::copy(c1.begin(), c1.end(), std::ostream_iterator<char>(std::cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif

