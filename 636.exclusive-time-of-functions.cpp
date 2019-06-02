
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

struct TimeInfo {
    int funid;
    int start;
    int end;
    int time;

    bool subRange(const TimeInfo &r) {
        if (r.start > end) {
            return false;
        }
        if (funid == r.funid) {
            return true;
        }
        time -= r.time;
        return true;
    }
    TimeInfo(int i, int s) : funid(i), start(s) {}
};

class SortByStart {
public:
    bool operator()(const TimeInfo &l, const TimeInfo &r) {
        return l.start < r.start;
    }
};

class SortByFunID {
public:
    bool operator()(const TimeInfo &l, const TimeInfo &r) {
        return l.funid < r.funid;
    }
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<TimeInfo> funcs;
        vector<TimeInfo> stack;
        for (int i = 0; i < logs.size(); i++) {
            string &log = logs[i];
            int pos = 0;
            int tmp = log.find(':', pos);
            int id = atoi(log.substr(pos, tmp - pos).data());
            pos = tmp + 1;
            tmp = log.find(':', pos);
            string a = log.substr(pos, tmp - pos);
            pos = tmp + 1;
            int tm = atoi(log.substr(pos).data());
            if (a.compare("start") == 0) {
                stack.push_back(TimeInfo(id, tm));
            } else {
                auto last = stack.back();
                stack.pop_back();
                assert(last.funid == id);
                last.end = tm;
                last.time = tm - last.start + 1;
                funcs.push_back(last);
            }
        }
        std::sort(funcs.begin(), funcs.end(), SortByStart());
        for (int i = funcs.size() - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (!funcs[j].subRange(funcs[i])) {
                    continue;
                } else if (funcs[i].funid == funcs[j].funid) {
                    funcs.erase(funcs.begin() + i);
                    break;
                }
            }
        }
        std::sort(funcs.begin(), funcs.end(), SortByFunID());
        vector<int> ret(n);
        for (int i = 0; i < funcs.size(); i++) {
            ret[funcs[i].funid] += funcs[i].time;
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
//     1
// ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
    vector<string> v1 = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    auto ret = s.exclusiveTime(2, v1);
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, " "));
    cout<<std::endl;

    vector<string> v2 = {"0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"};
    ret = s.exclusiveTime(1, v2);
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, " "));
    cout<<std::endl;

//     3
// ["0:start:0","0:end:0","1:start:1","1:end:1","2:start:2","2:end:2","2:start:3","2:end:3"]
    vector<string> v3 = {"0:start:0","0:end:0","1:start:1","1:end:1","2:start:2","2:end:2","2:start:3","2:end:3"};
    ret = s.exclusiveTime(3, v3);
std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, " "));
    cout<<std::endl;

    return 0;
}
#endif
