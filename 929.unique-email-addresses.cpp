/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 *
 * https://leetcode.com/problems/unique-email-addresses/description/
 *
 * algorithms
 * Easy (75.29%)
 * Total Accepted:    101.1K
 * Total Submissions: 137.7K
 * Testcase Example:  '["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]'
 *
 * Every email consists of a local name and a domain name, separated by the @
 * sign.
 * 
 * For example, in alice@leetcode.com, alice is the local name, and
 * leetcode.com is the domain name.
 * 
 * Besides lowercase letters, these emails may contain '.'s or '+'s.
 * 
 * If you add periods ('.') between some characters in the local name part of
 * an email address, mail sent there will be forwarded to the same address
 * without dots in the local name.  For example, "alice.z@leetcode.com" and
 * "alicez@leetcode.com" forward to the same email address.  (Note that this
 * rule does not apply for domain names.)
 * 
 * If you add a plus ('+') in the local name, everything after the first plus
 * sign will be ignored. This allows certain emails to be filtered, for example
 * m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule
 * does not apply for domain names.)
 * 
 * It is possible to use both of these rules at the same time.
 * 
 * Given a list of emails, we send one email to each address in the list.  How
 * many different addresses actually receive mails? 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
 * Output: 2
 * Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually
 * receive mails
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= emails[i].length <= 100
 * 1 <= emails.length <= 100
 * Each emails[i] contains exactly one '@' character.
 * All local and domain names are non-empty.
 * Local names do not start with a '+' character.
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
#include <sstream>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif
#include <set>

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        string tmp;
        std::set<string> unique;
        for (size_t i = 0; i < emails.size(); i++) {
            normalizeEmail(emails[i], tmp);
            unique.insert(tmp);
        }
        return unique.size();
    }

    void normalizeEmail(const string &oldstr, string &newstr) {
        size_t next = 0;
        newstr.resize(oldstr.size());
        bool domain = false, skip = false;
        for (size_t i = 0; i < oldstr.size(); i++) {
            char ch = oldstr[i];
            if (domain) {
                newstr[next++] = ch;
                continue;
            }
            switch (ch)
            {
                case '.':
                    break;
                case '+':
                    skip = true;
                    break;
                case '@':
                    domain = true;
                    newstr[next++] = ch;
                    break;
                default:
                    if (!skip) {
                        newstr[next++] = ch;
                    }
                    break;
            }
        }
        newstr.resize(next);
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    string tmp;
    s.normalizeEmail("a.b.c@baidu.com", tmp);
    assert(tmp == "abc@baidu.com");
    s.normalizeEmail("ab+dd+@baidu.com", tmp);
    assert(tmp == "ab@baidu.com");
    s.normalizeEmail("ab+cd.dd@baidu.com", tmp);
    assert(tmp == "ab@baidu.com");
    s.normalizeEmail("a.b+cd.dd@baidu.com", tmp);
    assert(tmp == "ab@baidu.com");

    vector<string> emails = {
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"
    };
    assert(s.numUniqueEmails(emails) == 2);
    return 0;
}
#endif


