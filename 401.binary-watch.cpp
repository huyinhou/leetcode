/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (45.08%)
 * Total Accepted:    61.6K
 * Total Submissions: 136.4K
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 * 
 * For example, the above binary watch reads "3:25".
 * 
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 * 
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 * 
 * 
 * Note:
 * 
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cstddef>
#include <cassert>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::cout;
using std::vector;
#endif
#include <sstream>
#include <iomanip>
using std::ostringstream;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int h = 0, m = num - h;
        vector<string> result;
        vector<int> hours;
        vector<int> minutes;
        
        for (; h <= num; h++, m--) {
            hours.clear();
            allCombine(hours, 4, h);
            minutes.clear();
            allCombine(minutes, 6, m);
            vector<int>::iterator ih, im;
            for (ih = hours.begin(); ih != hours.end(); ih++) {
                if (*ih >= 12) {
                    continue;
                }
                for (im = minutes.begin(); im != minutes.end(); im++) {
                    if (*im >= 60) {
                        continue;
                    }
                    ostringstream oss;
                    oss<<*ih<<":"<<std::setw(2)<<std::setfill('0')<<*im;
                    result.push_back(oss.str());
                }
            }
        }
        return result;
    }

    // 低n个位中选r个位置1的所有数字
    void allCombine(vector<int> &nums, int n, int r) {
        if (r <= 0) {
            nums.push_back(0);
            return;
        }
        if (r > n) {
            return;
        }
        vector<int> masks(r);
        vector<int> maxmk(r);
        for (int i = 0; i < r; i++) {
            masks[i] = i;
            maxmk[i] = n - r + i + 1;
        }
        do {
            // 构造数字
            int tmp = 0, i = 0;
            for (; i < r; i++) {
                tmp |= (1 << masks[i]);
            }
            nums.push_back(tmp);

            i = r - 1;
            while (i >= 0 && (masks[i] >= (maxmk[i] - 1)))
                i--;
            if (i < 0) {
                break;
            }
            masks[i]++;
            for (int j = i + 1; j < r; j++) {
                masks[j] = masks[j - 1] + 1;
            }
        } while (masks[0] < maxmk[0]);
    }
};

#ifdef LEETCODE
#include <algorithm>
#include <iterator>
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums;
    for (int i = 0; i <= 6; i++) {
        nums.clear();
        s.allCombine(nums, 6, i);
        std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(cout, ","));
        cout<<std::endl;
    }
    for (int i = 0; i <= 10; i++) {
        cout<<"i = "<<i<<std::endl;
        vector<string> ret = s.readBinaryWatch(i);
        std::copy(ret.begin(), ret.end(), std::ostream_iterator<string>(cout, " "));
    }
    return 0;
}
#endif

