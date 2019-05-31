
#define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#endif

struct Range {
    int first;
    int last;

    Range(): first(-1), last(-1) {}

    bool unionRange(struct Range &r) {
        if (r.first > first && r.first < last) {
            last = std::max(last, r.last);
            return true;
        }
        return false;
    }
};

bool operator<(const Range &l, const Range &r) {
    return l.first < r.first;
}

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<Range> pos(26);
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (pos[idx].first < 0) {
                pos[idx].first = i;
            }
            pos[idx].last = i;
        }
        vector<int> ret;
        std::sort(pos.begin(), pos.end());
        int i = 0;
        while (i < pos.size()) {
            Range tmp = pos[i];
            i++;
            if (tmp.first < 0) {
                continue;
            }
            while (i < pos.size()) {
                if (!tmp.unionRange(pos[i])) {
                    break;
                }
                i++;
            }
            ret.push_back(tmp.last - tmp.first + 1);
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    auto ret = s.partitionLabels("ababcbacadefegdehijhklij");
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    ret = s.partitionLabels("qiejxqfnqceocmy");
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    return 0;
}
#endif
