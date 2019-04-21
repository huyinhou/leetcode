
// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <stack>
#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ret;
        std::stack<int> nodes;
        int index = 0;
        ListNode *n = head;
        while (n != nullptr) {
            ret.push_back(n->val);
            while (!nodes.empty()) {
                if (n->val > ret[nodes.top()]) {
                    ret[nodes.top()] = n->val;
                    nodes.pop();
                } else {
                    break;
                }
            }
            
            nodes.push(index);
            index++;
            n = n->next;
        }
        while (!nodes.empty()) {
            ret[nodes.top()] = 0;
            nodes.pop();
        }
        return ret;
    }
};

#ifdef LEETCODE
ListNode *make_list(vector<int> &nodes) {
    ListNode *head = nullptr;
    for (auto it = nodes.rbegin(); it != nodes.rend(); it++) {
        ListNode *n = new ListNode(*it);
        n->next = head;
        head = n;
    }
    return head;
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> n1{2,1,5};
    ListNode *node = make_list(n1);
    vector<int> ret = s.nextLargerNodes(node);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<int>(cout, ", "));
    cout<<std::endl;

    vector<int> n2{2,7,4,3,5};
    node = make_list(n2);
    ret = s.nextLargerNodes(node);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<int>(cout, ", "));
    cout<<std::endl;

    vector<int> n3{1,7,5,1,9,2,5,1};
    node = make_list(n3);
    ret = s.nextLargerNodes(node);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
