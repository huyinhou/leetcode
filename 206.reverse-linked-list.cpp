/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (53.07%)
 * Total Accepted:    529K
 * Total Submissions: 996.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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

#include <cstddef>

// #define LEETEST
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
    ListNode* reverseList(ListNode* head) {
        ListNode *pb = NULL;
        while (head != NULL) {
            ListNode *tmp = head->next;
            head->next = pb;
            pb = head;
            head = tmp;
        }
        return pb;
    }
};

#ifdef LEETEST
#include <cassert>
#include <vector>
#include <iostream>
using std::vector;

void print_list(ListNode *p) {
    while (p != NULL) {
        std::cout << p->val << " - ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<ListNode> nodes(10);
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].val = i + 1;
        nodes[i].next = &nodes[i+1];
    }
    nodes[9].next = NULL;
    ListNode *h = s.reverseList(&nodes[0]);
    print_list(h);
}
#endif

