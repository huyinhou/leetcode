/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 *
 * https://leetcode.com/problems/delete-node-in-a-linked-list/description/
 *
 * algorithms
 * Easy (52.24%)
 * Total Accepted:    268.6K
 * Total Submissions: 514.1K
 * Testcase Example:  '[4,5,1,9]\n5'
 *
 * Write a function to delete a node (except the tail) in a singly linked list,
 * given only access to that node.
 * 
 * Given linked list -- head = [4,5,1,9], which looks like following:
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [4,5,1,9], node = 5
 * Output: [4,1,9]
 * Explanation: You are given the second node with value 5, the linked list
 * should become 4 -> 1 -> 9 after calling your function.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [4,5,1,9], node = 1
 * Output: [4,5,9]
 * Explanation: You are given the third node with value 1, the linked list
 * should become 4 -> 5 -> 9 after calling your function.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The linked list will have at least two elements.
 * All of the nodes' values will be unique.
 * The given node will not be the tail and it will always be a valid node of
 * the linked list.
 * Do not return anything from your function.
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
#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() {}
};
#endif

class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node != NULL) {
            if (node->next != NULL) {
                node->val = node->next->val;
                if (node->next->next == NULL) {
                    node->next = NULL;  // delete last node
                }
            }
            node = node->next;
        }
    }
};

#ifdef LEETCODE
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
    nodes.rbegin()->next = NULL;
    s.deleteNode(&nodes[1]);
    print_list(&nodes[0]);
    return 0;
}
#endif
