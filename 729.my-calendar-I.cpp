
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
#include <list>
using namespace std;
#endif

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = booking.begin();
        while (it != booking.end()) {
            if (start == it->start) {
                return false;
            } else if(start > it->start) {
                if (start < it->end) {
                    return false;
                }
            } else {
                if (end > it->start) {
                    return false;
                }
                break;
            }
            it++;
        }
        booking.insert(it, days_range{start, end});
        return true;
    }

private:
    struct days_range
    {
        int start;
        int end;
        bool operator< (days_range &o) {
            return start < o.start;
        }
    };
    list<days_range> booking;
};


#ifdef LEETCODE
int main(int argc, char *argv[]) {
    MyCalendar mc;
    assert(mc.book(1, 10));
    assert(!mc.book(1, 20));
    assert(!mc.book(0, 5));
    assert(!mc.book(9, 20));
    assert(mc.book(10, 20));

    /*
    ["MyCalendar","book","book","book","book","book","book","book","book","book","book"]
[[],[47,50],[33,41],[39,45],[33,42],[25,32],[26,35],[19,25],[3,8],[8,13],[18,27]]
[null,true,true,false,false,true,false,true,true,true,false]
     */
    MyCalendar m2;
    assert(m2.book(47, 50));
    assert(m2.book(33, 41)); 
    assert(!m2.book(39, 45));
    assert(!m2.book(33, 42));
    assert(m2.book(25, 32));
    return 0;
}
#endif
