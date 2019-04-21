/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 *
 * https://leetcode.com/problems/unique-morse-code-words/description/
 *
 * algorithms
 * Easy (74.26%)
 * Total Accepted:    79.2K
 * Total Submissions: 106.4K
 * Testcase Example:  '["gin", "zen", "gig", "msg"]'
 *
 * International Morse Code defines a standard encoding where each letter is
 * mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b"
 * maps to "-...", "c" maps to "-.-.", and so on.
 * 
 * For convenience, the full table for the 26 letters of the English alphabet
 * is given below:
 * 
 * 
 * 
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * 
 * Now, given a list of words, each word can be written as a concatenation of
 * the Morse code of each letter. For example, "cba" can be written as
 * "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-"). We'll
 * call such a concatenation, the transformation of a word.
 * 
 * Return the number of different transformations among all words we have.
 * 
 * 
 * Example:
 * Input: words = ["gin", "zen", "gig", "msg"]
 * Output: 2
 * Explanation: 
 * The transformation of each word is:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 * 
 * There are 2 different transformations, "--...-." and "--...--.".
 * 
 * 
 * Note:
 * 
 * 
 * The length of words will be at most 100.
 * Each words[i] will have length in range [1, 12].
 * words[i] will only consist of lowercase letters.
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
#include <set>
#include <sstream>
using std::vector;
using std::string;
using std::cout;
#endif

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        std::set<string> ret;
        for (size_t i = 0; i < words.size(); i++) {
            std::ostringstream oss;
            string &w = words[i];
            for (size_t k = 0; k < w.size(); k++) {
                oss<<morseTable[w[k] - 'a'];
            }
            ret.insert(oss.str());
        }
        return ret.size();
    }
    static const char *morseTable[];
};

const char *Solution::morseTable[] = {
    ".-", "-...", "-.-.", "-..", ".",
    "..-.", "--.", "....", "..", ".---", 
    "-.-", ".-..", "--", "-.", "---", 
    ".--.", "--.-", ".-.", "...", "-", 
    "..-", "...-", ".--", "-..-", "-.--",
    "--.."
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<string> words;
    words.push_back("gin");
    words.push_back("zen");
    words.push_back("gig");
    words.push_back("msg");
    assert(s.uniqueMorseRepresentations(words) == 2);
    return 0;
}
#endif
