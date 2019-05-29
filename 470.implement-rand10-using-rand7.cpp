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

int rand7() {
    return rand() % 7 + 1;
}
#endif

class Solution {
public:
    int rand10() {
        int a = rand7(), b = rand7();
        while (a == 7) {
            a = rand7();
        }
        while (b > 5) {
            b = rand7();
        }
        return a % 2 * 5 + b;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    srand(time(nullptr));
    Solution s;
    assert(rand7() <= 7);
    int count[10] = {0};
    for (int i = 0; i < 1000; i++) {
        count[s.rand10() - 1]++;
    }
    for (int i = 0; i < 10; i++) {
        cout<<count[i]<<" ";
    }
    cout<<std::endl;
    return 0;
}
#endif