
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
#include <set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> nums;
        for (int i = 0; i < G.size(); i++) {
            nums.insert(G[i]);
        }
        int ans = 0;
        int count = 0;
        while (head != nullptr) {
            auto it = nums.find(head->val);
            if (it == nums.end()) {
                if (count > 0) {
                    ans++;
                }
                count = 0;
            } else {
                count++;
                nums.erase(it);
            }
            head = head->next;
        }
        return ans + (count > 0);
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

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {0,1,2,3};
    ListNode *node = buildList(v1);
    vector<int> g1 = {0,1,3};
    assert(s.numComponents(node, g1) == 2);

    vector<int> v2 = {0,1,2,3,4};
    node = buildList(v2);
    vector<int> g2 = {0,3,1,4};
    assert(s.numComponents(node, g2) == 2);

    vector<int> v3 = {0};
    node = buildList(v3);
    assert(s.numComponents(node, v3) == 1);

    vector<int> v4 = {0,1,2};
    node = buildList(v4);
    vector<int> g4 = {0,2};
    assert(s.numComponents(node, g4) == 2);
    return 0;
}
#endif
