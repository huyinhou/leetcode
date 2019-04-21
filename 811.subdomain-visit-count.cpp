/*
 * @lc app=leetcode id=811 lang=cpp
 *
 * [811] Subdomain Visit Count
 *
 * https://leetcode.com/problems/subdomain-visit-count/description/
 *
 * algorithms
 * Easy (64.16%)
 * Total Accepted:    38.5K
 * Total Submissions: 59.4K
 * Testcase Example:  '["9001 discuss.leetcode.com"]'
 *
 * A website domain like "discuss.leetcode.com" consists of various subdomains.
 * At the top level, we have "com", at the next level, we have "leetcode.com",
 * and at the lowest level, "discuss.leetcode.com". When we visit a domain like
 * "discuss.leetcode.com", we will also visit the parent domains "leetcode.com"
 * and "com" implicitly.
 * 
 * Now, call a "count-paired domain" to be a count (representing the number of
 * visits this domain received), followed by a space, followed by the address.
 * An example of a count-paired domain might be "9001 discuss.leetcode.com".
 * 
 * We are given a list cpdomains of count-paired domains. We would like a list
 * of count-paired domains, (in the same format as the input, and in any
 * order), that explicitly counts the number of visits to each subdomain.
 * 
 * 
 * Example 1:
 * Input: 
 * ["9001 discuss.leetcode.com"]
 * Output: 
 * ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
 * Explanation: 
 * We only have one website domain: "discuss.leetcode.com". As discussed above,
 * the subdomain "leetcode.com" and "com" will also be visited. So they will
 * all be visited 9001 times.
 * 
 * 
 * 
 * 
 * Example 2:
 * Input: 
 * ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
 * Output: 
 * ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1
 * intel.mail.com","951 com"]
 * Explanation: 
 * We will visit "google.mail.com" 900 times, "yahoo.com" 50 times,
 * "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will
 * visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and
 * "org" 5 times.
 * 
 * 
 * 
 * Notes: 
 * 
 * 
 * The length of cpdomains will not exceed 100. 
 * The length of each domain name will not exceed 100.
 * Each address will have either 1 or 2 "." characters.
 * The input count in any count-paired domain will not exceed 10000.
 * The answer output can be returned in any order.
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
#include <map>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
using std::map;
#endif

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ret;
        map<string, int> cntmap;
        for (size_t i = 0; i < cpdomains.size(); i++) {
            string &domain = cpdomains[i];
            int count = atoi(domain.c_str());
            auto it = std::find(domain.begin(), domain.end(), ' ');
            if (it == domain.end()) {
                continue;
            }
            it++;
            while (it != domain.end()) {
                string d(it, domain.end());
                auto im = cntmap.find(d);
                if (im == cntmap.end()) {
                    cntmap[d] = count;
                } else {
                    im->second += count;
                }
                it = std::find(it, domain.end(), '.');
                if (it != domain.end()) {
                    it++;
                }
            }
        }
        for (auto it = cntmap.begin(); it != cntmap.end(); it++) {
            ostringstream oss;
            oss<<it->second<<" "<<it->first;
            ret.push_back(oss.str());
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<string> d1 = {
        "9001 discuss.leetcode.com"
    };
    auto ret = s.subdomainVisits(d1);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, ", "));
    cout<<std::endl;

    vector<string> d2 = {
        "900 google.mail.com",
        "50 yahoo.com",
        "1 intel.mail.com",
        "5 wiki.org"
    };
    ret = s.subdomainVisits(d2);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif

