/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (49.35%)
 * Total Accepted:    248.3K
 * Total Submissions: 500.7K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cstddef>
#include <cstdio>
#include <string>
using std::string;
#endif

class Solution {
    struct letter_info {
        int next; // 下一个首次出现的字符
        int index;  // >=0首次出现位置，<-1多次出现，=-1未出现
    };

public:
    int firstUniqChar(string s) {
        if (s.empty()) {
            return -1;
        }

        int last_unique = -1;
        letter_info letters[26];
        for (int i = 0; i < 26; i++) {
            letters[i].next = -1;
            letters[i].index = -1;
        }
        for (int i = 0; i < s.size(); i++) {
            int k = s[i] - 'a';
            if (letters[k].index < -1 || letters[k].index >= 0) {
                letters[k].index = -2;
                continue;
            } 
            // 首次出现该字符
            letters[k].index = i;
            if (last_unique < 0) {
                last_unique = k;
            } else {
                letters[last_unique].next = k;
                last_unique = k;
            }
        }
        int k = s[0] - 'a';
        while (k >= 0 && letters[k].index < 0) {
            k = letters[k].next;
        }
        if (k < 0) {
            return -1;
        }
        return letters[k].index;
    }
};


#ifdef LEETCODE
#include <cassert>
int main(int argc, char *argv[]) {
    Solution s;
    string str;
    str = "";
    assert(-1 == s.firstUniqChar(str));
    str = "leetcode";
    assert(0 == s.firstUniqChar(str));
    str = "loveleetcode";
    assert(2 == s.firstUniqChar(str));
    return 0;
}
#endif

