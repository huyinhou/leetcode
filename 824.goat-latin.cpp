/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 *
 * https://leetcode.com/problems/goat-latin/description/
 *
 * algorithms
 * Easy (56.97%)
 * Total Accepted:    28.8K
 * Total Submissions: 50.4K
 * Testcase Example:  '"I speak Goat Latin"'
 *
 * A sentence S is given, composed of words separated by spaces. Each word
 * consists of lowercase and uppercase letters only.
 * 
 * We would like to convert the sentence to "Goat Latin" (a made-up language
 * similar to Pig Latin.)
 * 
 * The rules of Goat Latin are as follows:
 * 
 * 
 * If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of
 * the word.
 * For example, the word 'apple' becomes 'applema'.
 * 
 * If a word begins with a consonant (i.e. not a vowel), remove the first
 * letter and append it to the end, then add "ma".
 * For example, the word "goat" becomes "oatgma".
 * 
 * Add one letter 'a' to the end of each word per its word index in the
 * sentence, starting with 1.
 * For example, the first word gets "a" added to the end, the second word gets
 * "aa" added to the end and so on.
 * 
 * 
 * Return the final sentence representing the conversion from S to Goat
 * Latin. 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "I speak Goat Latin"
 * Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "The quick brown fox jumped over the lazy dog"
 * Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa
 * hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 * 
 * 
 * 
 * 
 * Notes:
 * 
 * 
 * S contains only uppercase, lowercase and spaces. Exactly one space between
 * each word.
 * 1 <= S.length <= 150.
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
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif
#include <sstream>
class Solution {
public:
    string toGoatLatin(string S) {
        std::ostringstream oss;
        int index = 0;
        char prevch = ' ';
        char consonant = '\0';
        for (size_t i = 0; i < S.length(); i++) {
            if (isspace(S[i])) {
                if (!isspace(prevch)) {
                    // 单词结尾
                    if (consonant != '\0') {
                        oss<<consonant;
                    }
                    oss<<"ma";
                    for (int j = 0; j < index; j++) {
                        oss<<'a';
                    }
                }
                oss<<S[i];
                prevch = S[i];
                continue;
            }
            if (isspace(prevch)) {
                // 新单词开始
                index++;
                // cout<<index<<std::endl;
                if (isvowel(S[i])) {
                    oss<<S[i];
                    consonant = '\0';
                } else {
                    consonant = S[i];
                }
            } else {
                oss<<S[i];
            }
            prevch = S[i];
        }
        if (!isspace(prevch)) {
            // 单词结尾
            if (consonant != '\0') {
                oss<<consonant;
            }
            oss<<"ma";
            for (int j = 0; j < index; j++) {
                oss<<'a';
            }
        }
        return oss.str();
    }

    static bool isvowel(char ch) {
        switch(ch) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                return true;
        }
        return false;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    cout<<s.toGoatLatin("I speak Goat Latin")<<std::endl;
    assert(s.toGoatLatin("I speak Goat Latin") == "Imaa peaksmaaa oatGmaaaa atinLmaaaaa");
    assert(s.toGoatLatin("  The quick brown fox jumped over the lazy dog ") 
        == "  heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa ");
    return 0;
}
#endif
