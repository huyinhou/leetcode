
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *head = nullptr;
        ListNode *last = nullptr;

        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int v = l1->val + l2->val + carry;
            if (v >= 10) {
                v -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            if (head == nullptr) {
                head = new ListNode(v);
                last = head;
            } else {
                last->next = new ListNode(v);
                last = last ->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *remain = nullptr;
        if (l1 != nullptr) {
            remain = l1;
        }
        if (l2 != nullptr) {
            remain = l2;
        }
        while (remain != nullptr) {
            int v = remain->val + carry;
            if (v >= 10) {
                v -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            if (head == nullptr) {
                head = new ListNode(v);
                last = head;
            } else {
                last->next = new ListNode(v);
                last = last ->next;
            }
            remain = remain->next;
        }
        if (carry) {
            last->next = new ListNode(carry);
        }
        return reverseList(head);
    }

    ListNode *reverseList(ListNode *l) {
        ListNode *ret = nullptr;
        while (l != nullptr) {
            ListNode *temp = l->next;
            l->next = ret;
            ret = l;
            l = temp;
        }
        return ret;
    }
};

#ifdef LEETCODE
ListNode* buildList(vector<int> vals) {
    ListNode *node = nullptr;
    for (int i = vals.size() - 1; i >= 0; i--) {
        ListNode *tmp = new ListNode(vals[i]);
        tmp->next = node;
        node = tmp;
    }
    return node;
}

void dumpList(ListNode *l) {
    while (l != nullptr) {
        cout<<l->val<<" ";
        l = l->next;
    }
    cout<<std::endl;
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {7,2,4,3};
    vector<int> v2 = {5,6,4};
    ListNode *l1 = buildList(v1);
    ListNode *l2 = buildList(v2);

    auto ret = s.addTwoNumbers(l1, l2);
    dumpList(ret);

    vector<int> v3 = {1,9,9,9};
    vector<int> v4 = {1};
    ListNode *l3 = buildList(v3);
    ListNode *l4 = buildList(v4);
    ret = s.addTwoNumbers(l3, l4);
    dumpList(ret);
    return 0;
}
#endif
