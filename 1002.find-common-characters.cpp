/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * https://leetcode.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (68.33%)
 * Total Accepted:    15.8K
 * Total Submissions: 23.8K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * Given an array A of strings made only from lowercase letters, return a list
 * of all characters that show up in all strings within the list (including
 * duplicates).  For example, if a character occurs 3 times in all strings but
 * not 4 times, you need to include that character three times in the final
 * answer.
 * 
 * You may return the answer in any order.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["bella","label","roller"]
 * Output: ["e","l","l"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["cool","lock","cook"]
 * Output: ["c","o"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] is a lowercase letter
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
#include <iterator>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

class Solution {
public:
    vector<string> commonChars(vector<string>& a) {
        vector<string> ret;
        if (a.empty()) {
            return ret;
        }
        int cnt[26] = {0};
        string &str = a[0];
        for (size_t i = 0; i < str.size(); i++) {
            cnt[str[i] - 'a']++;
        }
        for (size_t i = 1; i < a.size(); i++) {
            string &tmpstr = a[i];
            int tmpcnt[26] = {0};
            for (size_t j = 0; j < tmpstr.size(); j++) {
                tmpcnt[tmpstr[j] - 'a']++;
            }
            bool allzero = true;
            for (size_t j = 0; j < 26; j++) {
                if (cnt[j] > tmpcnt[j]) {
                    cnt[j] = tmpcnt[j];
                }
                if (cnt[j]) {
                    allzero = false;
                }
            }
            if (allzero) {
                break;
            }
        }
        for (size_t i = 0; i < 26; i++) {
            for (size_t j = 0; j < cnt[i]; j++) {
                ret.push_back(string(1, 'a' + i));
            }
        }

        return ret;
    }
};

#ifdef LEETCODE

int main(int argc, char *argv[]) {
    Solution s;
    vector<string> v1;
    v1.push_back("bella");
    v1.push_back("label");
    v1.push_back("roller");
    auto ret = s.commonChars(v1);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, ", "));
    cout<<std::endl;

    vector<string> v2;
    v2.push_back("cool");
    v2.push_back("lock");
    v2.push_back("cook");
    ret = s.commonChars(v2);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, ", "));
    cout<<std::endl;

    vector<string> v3{"acabcddd","bcbdbcbd","baddbadb","cbdddcac","aacbcccd","ccccddda","cababaab","addcaccd"};
    ret = s.commonChars(v3);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
