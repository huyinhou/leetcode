
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
#include <cmath>
using namespace std;
#endif


struct Operator {
    Operator(int o) {
        op = EOps(o);
    }
    enum EOps {
        Mul,
        Div,
        Add,
        Sub
    };
    EOps op;

    int priority(const Operator &o) {
        if (op < Add) {
            if (o.op < Add) {
                return 0;
            }
            return 1;
        }
        if (o.op < Add) {
            return -1;
        }
        return 0;
    }

    int calc(int n1, int n2) {
        if (op == Mul) {
            return n1 * n2;
        } 
        if (op == Div) {
            return (int)std::floor(n1 * 1.0 / n2);
        }
        if (op == Add) {
            return n1 + n2;
        }
        return n1 - n2;
    }

    Operator next() {
        return Operator((op + 1) % 4);
    }

    char tochar() const {
        if (op == Mul) {
            return '*';
        }
        if (op == Div) {
            return '/';
        }
        if (op == Add) {
            return '+';
        }
        if (op == Sub) {
            return '-';
        }
        return '?';
    }


};

void operator<<(std::ostream &oss, const Operator &op) {
    oss<<op.tochar();
}

class Solution {
public:
    int clumsy(int N) {
        Operator op(0);
        vector<int> nums;
        vector<Operator> ops;
        nums.push_back(N);
        while (--N > 0) {
            // std::copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
            // cout<<std::endl;
            // std::copy(ops.begin(), ops.end(), ostream_iterator<Operator>(cout, ", "));
            // cout<<std::endl;
            if (ops.size() > 0) {
                auto lastop = ops.back();
                int pri = op.priority(lastop);
                if (pri > 0) {  // 计算当前数字和最后一个数字 然后压栈最后一个数字
                    int n0 = nums.back();
                    nums.pop_back();
                    nums.push_back(op.calc(n0, N));
                } else { // 计算栈中最后两个数字，压栈
                    int n1 = nums.back();
                    nums.pop_back();
                    int n0 = nums.back();
                    nums.pop_back();
                    ops.pop_back();
                    nums.push_back(lastop.calc(n0, n1));
                    nums.push_back(N);
                    ops.push_back(op);
                }
            } else {
                nums.push_back(N);
                ops.push_back(op);
            }
            op = op.next();
        }
        // std::copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
        // cout<<std::endl;
        // std::copy(ops.begin(), ops.end(), ostream_iterator<Operator>(cout, ", "));
        // cout<<std::endl;
        if (ops.size() > 0) {
            auto lastop = ops.back();
            int n1 = nums.back();
            nums.pop_back();
            int n0 = nums.back();
            nums.pop_back();
            return lastop.calc(n0, n1);
        }
        return nums[0];
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    // assert(s.clumsy(1) == 1);
    // assert(s.clumsy(2) == 2);
    // assert(s.clumsy(3) == 6);
    // assert(s.clumsy(4) == 7);
    // assert(s.clumsy(5) == 7);
    assert(s.clumsy(10) == 12);
    return 0;
}
#endif
