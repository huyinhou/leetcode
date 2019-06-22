
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        srand(time(nullptr));
        data = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int count = 0;
        ListNode *sel = nullptr;
        ListNode *list = data;
        while (list != nullptr) {
            if (rand() % (++count) == 0) {
                sel = list;
            }
            list = list->next;
        }
        return sel->val;
    }

private:
    ListNode *data;
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

int main(int argc, char *argv[]) {
    vector<int> v1 = {1, 2, 3};
    ListNode *l1 = buildList(v1);

    Solution s(l1);
    for (int i = 0; i < 20; i++) {
        cout<<s.getRandom()<<std::endl;
    }
    return 0;
}
#endif
