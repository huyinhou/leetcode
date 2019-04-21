/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (34.59%)
 * Total Accepted:    132.3K
 * Total Submissions: 382.5K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 */
// #define LEETCODE
#ifdef LEETCODE
#include <iostream>
#include <algorithm>
using std::cout;
using std::for_each;
#endif

#include <string>
#include <vector>
#include <map>
using std::string;
using std::vector;
using std::map;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> parts = splitString(str);
        if (parts.size() != pattern.size()) {
            return false;
        }
        map<char, string> psmap;
        map<string, char> spmap;
        for (size_t i = 0; i < pattern.size(); i++) {
            auto itps = psmap.find(pattern[i]);
            if (itps != psmap.end()) {
                if (itps->second.compare(parts[i]) != 0) {
                    return false;
                }
            } else {
                psmap[pattern[i]] = parts[i];
            }
            auto itsp = spmap.find(parts[i]);
            if (itsp != spmap.end()) {
                if (itsp->second != pattern[i]) {
                    return false;
                }
            } else {
                spmap[parts[i]] = pattern[i];
            }
        }
        return true;
    }

    vector<string> splitString(string &s) {
        vector<string> parts;
        size_t pos = 0;
        while (pos < s.size()) {
            size_t end = s.find(" ", pos);
            if (end == string::npos) {
                parts.push_back(s.substr(pos));
                return parts;
            }
            if (end > pos) {
                parts.push_back(s.substr(pos, end - pos));
            }
            pos = end + 1;
        }
        return parts;
    }
};

#ifdef LEETCODE
#include <cassert>

int main(int argc, char *argv[]) {
    Solution s;
    string str = "dog cat cat dog";
    vector<string> parts = s.splitString(str);
    for_each(parts.begin(), parts.end(), [](string &s) {
        cout<<s<<std::endl;
    });
    assert(s.wordPattern("abba", "dog cat cat dog"));
    assert(s.wordPattern("abba", " dog  cat cat dog "));
    assert(!s.wordPattern("abba", "dog cat cat fish"));
    assert(!s.wordPattern("aaaa", "dog cat cat dog"));
    assert(!s.wordPattern("abba", "dog dog dog dog"));
    assert(!s.wordPattern("abba", "dog dog dog"));
}
#endif

