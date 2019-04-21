/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (47.52%)
 * Total Accepted:    92.6K
 * Total Submissions: 193.9K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
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
using std::string;
using std::ostringstream;
#endif

class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {0};
        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;
        }
        // std::copy(&count[0], &count[0] + 128, std::ostream_iterator<int>(std::cout, ", "));
        // std::cout<<std::endl;
        int odd = 0, total = 0;
        int range[2][2] = {
            {'a', 'z'},
            {'A', 'Z'}
        };
        for (int i = 0; i < 2; i++) {
            for (int j = range[i][0]; j <= range[i][1]; j++) {
                if (count[j] % 2) {
                    total += count[j] - 1;
                    odd = 1;
                } else {
                    total += count[j];
                }
            }
        }
        return total + odd;
    }
};

#ifdef LEETCODE
#include <iostream>
#include <cassert>
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.longestPalindrome("abccccdd") == 7);
    assert(s.longestPalindrome("abcCccdd") == 5);
    assert(s.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") == 983);
    return 0;
}
#endif
