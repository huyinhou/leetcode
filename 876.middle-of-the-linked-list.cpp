/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 *
 * https://leetcode.com/problems/middle-of-the-linked-list/description/
 *
 * algorithms
 * Easy (63.42%)
 * Total Accepted:    55.3K
 * Total Submissions: 86.9K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a non-empty, singly linked list with head node head, return a middle
 * node of linked list.
 * 
 * If there are two middle nodes, return the second middle node.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: Node 3 from this list (Serialization: [3,4,5])
 * The returned node has value 3.  (The judge's serialization of this node is
 * [3,4,5]).
 * Note that we returned a ListNode object ans, such that:
 * ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next
 * = NULL.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5,6]
 * Output: Node 4 from this list (Serialization: [4,5,6])
 * Since the list has two middle nodes with values 3 and 4, we return the
 * second one.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given list will be between 1 and 100.
 * 
 * 
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <sstream>
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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *p1 = head, *p2 = head;
        while(p2 != nullptr){
            if ((p2 = p2->next) == nullptr) {
                break;
            }
            p1 = p1->next;
            if ((p2 = p2->next) == nullptr) {
                break;
            }
        }
        return p1;
    }
};

#ifdef LEETCODE
ListNode *buildList(vector<int> &vals) {
    ListNode *head = nullptr, **prev = &head;
    for (size_t i = 0; i < vals.size(); i++) {
        ListNode *node = new ListNode(vals[i]);
        *prev = node;
        prev = &node->next;
    }
    return head;
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1{1,2,3,4,5};
    auto ret = buildList(v1);
    ret = s.middleNode(ret);
    cout<<ret->val<<std::endl;
    assert(ret->val == 3);
    
    vector<int> v2{1,2,3,4,5,6};
    ret = buildList(v2);
    ret = s.middleNode(ret);
    assert(ret->val == 4);
    return 0;
}
#endif
