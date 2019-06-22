
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



#ifdef LEETCODE
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto it = data.find(key);
        if (it == data.end()) {
            return string();
        }
        auto itv = std::lower_bound(it->second.begin(), it->second.end(), timestamp, 
            [](const timevalue &v, const int t) {
                return v.timestamp < t;
            });
        
        if (itv == it->second.end()) {
            return it->second.rbegin()->value;
        }
        if (itv->timestamp == timestamp) {
            return itv->value;
        } else if (itv > it->second.begin()) {
            itv--;
            return itv->value;
        }
        return string();
    }

private:
    struct timevalue {
        timevalue(int t, string &s) {
            timestamp = t;
            value = s;
        }
        int timestamp;
        string value;
    };

    map<string, vector<timevalue> > data;
};

int main(int argc, char *argv[]) {
    TimeMap *obj = new TimeMap();
    obj->set("love","high",10);
    obj->set("love","low",20);
    cout<<obj->get("love", 5)<<std::endl;
    cout<<obj->get("love", 10)<<std::endl;
    cout<<obj->get("love", 15)<<std::endl;
    cout<<obj->get("love", 20)<<std::endl;
    cout<<obj->get("love", 21)<<std::endl;
    return 0;
}
#endif
