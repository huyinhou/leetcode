/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 *
 * https://leetcode.com/problems/first-bad-version/description/
 *
 * algorithms
 * Easy (29.15%)
 * Total Accepted:    207.2K
 * Total Submissions: 710.8K
 * Testcase Example:  '5\n4'
 *
 * You are a product manager and currently leading a team to develop a new
 * product. Unfortunately, the latest version of your product fails the quality
 * check. Since each version is developed based on the previous version, all
 * the versions after a bad version are also bad.
 * 
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the
 * first bad one, which causes all the following ones to be bad.
 * 
 * You are given an API bool isBadVersion(version) which will return whether
 * version is bad. Implement a function to find the first bad version. You
 * should minimize the number of calls to the API.
 * 
 * Example:
 * 
 * 
 * Given n = 5, and version = 4 is the first bad version.
 * 
 * call isBadVersion(3) -> false
 * call isBadVersion(5) -> true
 * call isBadVersion(4) -> true
 * 
 * Then 4 is the first bad version. 
 * 
 */
// Forward declaration of isBadVersion API.
// #define LEETCODE
#ifdef LEETCODE
#include <iostream>
using std::cout;
#endif

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        checkBadVersion(1, n);
        return m_firstBad;
    }

    void checkBadVersion(long start, long end) {
        if (start > end) {
            return;
        }
        long mid = (start + end) / 2;
        if (isBadVersion(mid)) {
            m_firstBad = mid;
            checkBadVersion(start, mid - 1);
        } else {
            checkBadVersion(mid + 1, end);
        }
    }

private:
    int m_firstBad;
};

#ifdef LEETCODE
static int s_firstBad;
bool isBadVersion(int version) {
    return version >= s_firstBad;
}

#include <cassert>

int main(int argc, char *argv[]) {
    s_firstBad = 4;
    for (int n = 4; n < 20; n++) {
        Solution s;
        assert(s_firstBad == s.firstBadVersion(10));
    }
}
#endif
