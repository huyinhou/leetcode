
#define LEETCODE
#ifdef LEETCODE
#include <cassert>
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
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ret;
        for (auto it = queries.begin(); it != queries.end(); it++) {
            ret.push_back(matchQuery(*it, pattern));
        }
        return ret;
    }

    bool matchQuery(const string &query, const string &pattern) {
        size_t i = 0, j = 0;
        for (; i < query.size() && j < pattern.size(); i++) {
            if (query[i] == pattern[j]) {
                j++;
                continue;
            }
            if (isupper(query[i])) {
                return false;
            }
        }
        if (j < pattern.size()) {
            return false;
        } else if (j == pattern.size()) {
            while (i < query.size()) {
                if (isupper(query[i])) {
                    return false;
                }
                i++;
            }
        }
        return (i == query.size());
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.matchQuery("abacFooBar", "aaFoB"));
    assert(!s.matchQuery("aFooBar", "aaFB"));
    assert(s.matchQuery("aaaaaFooBar", "aaFB"));
    assert(!s.matchQuery("FooBarTest", "FB"));
    assert(s.matchQuery("FrameBuffer", "FB"));
    return 0;
}
#endif
