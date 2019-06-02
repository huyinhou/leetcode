
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
    ListNode* oddEvenList(ListNode* l) {
        ListNode *head[2] = {nullptr};
        ListNode *last[2] = {nullptr};
        int i = 1;
        while (l != nullptr) {
            if (head[i] == nullptr) {
                head[i] = last[i] = l;
            } else {
                last[i]->next = l;
                last[i] = l;
            }
            l = l->next;
            i = (i + 1) % 2;
        }
        if (last[0]) {
            last[0]->next = nullptr;
        }
        if (head[1] == nullptr) {
            return head[0];
        }
        last[1]->next = head[0];
        
        return head[1];
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
    vector<int> v1 = {1,2,3,4,5};
    ListNode *l1 = buildList(v1);
    ListNode *ret = s.oddEvenList(l1);
    dumpList(ret);

    vector<int> v2 = {2,1,3,5,6,4,7};
    ListNode *l2 = buildList(v2);
    ret = s.oddEvenList(l2);
    dumpList(ret);

    vector<int> v3 = {2};
    ListNode *l3 = buildList(v3);
    ret = s.oddEvenList(l3);
    dumpList(ret);
    return 0;
}
#endif
