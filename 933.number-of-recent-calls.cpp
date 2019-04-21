/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 *
 * https://leetcode.com/problems/number-of-recent-calls/description/
 *
 * algorithms
 * Easy (68.99%)
 * Total Accepted:    19K
 * Total Submissions: 27.4K
 * Testcase Example:  '["RecentCounter","ping","ping","ping","ping"]\n[[],[1],[100],[3001],[3002]]'
 *
 * Write a class RecentCounter to count recent requests.
 * 
 * It has only one method: ping(int t), where t represents some time in
 * milliseconds.
 * 
 * Return the number of pings that have been made from 3000 milliseconds ago
 * until now.
 * 
 * Any ping with time in [t - 3000, t] will count, including the current ping.
 * 
 * It is guaranteed that every call to ping uses a strictly larger value of t
 * than before.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: inputs = ["RecentCounter","ping","ping","ping","ping"], inputs =
 * [[],[1],[100],[3001],[3002]]
 * Output: [null,1,2,3,3]
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Each test case will have at most 10000 calls to ping.
 * Each test case will call ping with strictly increasing values of t.
 * Each call to ping will have 1 <= t <= 10^9.
 * 
 * 
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
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

#include <queue>
using std::queue;

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int before = t - 3000;
        while (!q.empty()) {
            int a = q.front();
            if (a < before) {
                q.pop();
            } else {
                break;
            }
        }
        q.push(t);
        return q.size();
    }

private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    RecentCounter* obj = new RecentCounter();
    assert(obj->ping(1) == 1);
    assert(obj->ping(100) == 2);
    assert(obj->ping(3001) == 3);
    assert(obj->ping(3002) == 3);
    return 0;
}
#endif
