/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (35.35%)
 * Total Accepted:    210K
 * Total Submissions: 594.1K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
// #define LEETEST

#include<cstddef>
#ifdef LEETEST
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() {}
};
#endif

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **prev = &head;
        ListNode *p = head;
        while (p != NULL) {
            if (p->val == val) {
                *prev = p->next;
            } else {
                prev = &p->next;
            }
            p = p->next;
        }
        return head;
    }
};

#ifdef LEETEST
#include <vector>
#include <iostream>
#include <cassert>
using std::vector;

void print_list(ListNode *head) {
    while (head != NULL) {
        std::cout <<head->val<<"-";
        head=head->next;
    }
    std::cout<<std::endl;
}

int main(int argc, char *argv[]) {
    vector<ListNode> nodes(3);
    for (size_t i = 0; i < nodes.size(); i++) {
        nodes[i].val = i;
        nodes[i].next = &nodes[i+1];
        if ((i + 1) == nodes.size()) {
            nodes[i].next = NULL;
        }
    }
    Solution s;
    ListNode *head = &nodes[0];
    head = s.removeElements(head, 0);
    print_list(head);
    head = s.removeElements(head, 2);
    print_list(head);
    nodes[0].next = NULL;
    head = &nodes[0];
    assert(s.removeElements(head, 0) == NULL);
}
#endif
