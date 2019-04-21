/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 *
 * https://leetcode.com/problems/keys-and-rooms/description/
 *
 * algorithms
 * Medium (59.53%)
 * Total Accepted:    29.8K
 * Total Submissions: 49.8K
 * Testcase Example:  '[[1],[2],[3],[]]'
 *
 * There are N rooms and you start in room 0.  Each room has a distinct number
 * in 0, 1, 2, ..., N-1, and each room may have some keys to access the next
 * room. 
 * 
 * Formally, each room i has a list of keys rooms[i], and each key rooms[i][j]
 * is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j]
 * = v opens the room with number v.
 * 
 * Initially, all the rooms start locked (except for room 0). 
 * 
 * You can walk back and forth between rooms freely.
 * 
 * Return true if and only if you can enter every room.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1],[2],[3],[]]
 * Output: true
 * Explanation:  
 * We start in room 0, and pick up key 1.
 * We then go to room 1, and pick up key 2.
 * We then go to room 2, and pick up key 3.
 * We then go to room 3.  Since we were able to go to every room, we return
 * true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,3],[3,0,1],[2],[0]]
 * Output: false
 * Explanation: We can't enter the room with number 2.
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= rooms.length <= 1000
 * 0 <= rooms[i].length <= 1000
 * The number of keys in all rooms combined is at most 3000.
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

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        size_t nvisit = 0;
        vector<bool> flag(rooms.size());
        vector<int> visit;
        visit.push_back(0);
        while (!visit.empty()) {
            int r = visit.front();
            visit.erase(visit.begin());
            if (flag[r]) {
                continue;
            }
            nvisit++;
            flag[r] = true;
            vector<int> &next = rooms[r];
            for (vector<int>::iterator it = next.begin(); 
                it != next.end(); it++) {
                if (!flag[*it]) {
                    visit.push_back(*it);
                }
            }
        }
        return nvisit == rooms.size();
    }
};

#ifdef LEETCODE
vector<vector<int> > test_case1() {
    vector<vector<int> > rooms;
    vector<int> r0{1, 3};
    vector<int> r1{3, 0, 1};
    vector<int> r2{2};
    vector<int> r3{0};
    rooms.push_back(r0);
    rooms.push_back(r1);
    rooms.push_back(r2);
    rooms.push_back(r3);
    return rooms;
}

vector<vector<int> > test_case2() {
    vector<vector<int> > rooms;
    vector<int> r0{1};
    vector<int> r1{2};
    vector<int> r2{3};
    vector<int> r3{0};
    rooms.push_back(r0);
    rooms.push_back(r1);
    rooms.push_back(r2);
    rooms.push_back(r3);
    return rooms;
}

int main(int argc, char *argv[]) {
    Solution s;
    auto t1 = test_case1();
    assert(!s.canVisitAllRooms(t1));
    t1 = test_case2();
    assert(s.canVisitAllRooms(t1));
    return 0;
}
#endif
