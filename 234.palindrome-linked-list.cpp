/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (35.42%)
 * Total Accepted:    236.5K
 * Total Submissions: 667.6K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
#ifdef LEETEST
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
    bool isPalindrome(ListNode* head) {
        int length = listLength(head);
        ListNode *half = listNthEntry(head, length / 2 + length % 2);
        half = listReverse(half);
        ListNode *pl =head, *pr = half;
        while (pr != NULL) {
            if (pl->val != pr->val) {
                return false;
            }
            pr = pr->next;
            pl = pl->next;
        }
        return true;
    }

    int listLength(ListNode* head) {
        int length = 0;
        while (head != NULL) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* listNthEntry(ListNode *head, int nth) {
        while (nth > 0) {
            head = head->next;
            nth--;
        }
        return head;
    }

    ListNode *listReverse(ListNode* head) {
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

void init_list(vector<ListNode> &nums, int nlen) {
    nums.resize(nlen);
    int half = nums.size() / 2 + nums.size() % 2;
    for (int i = 0; i < nums.size(); i++) {
        if (i < half) {
            nums[i].val = i;
        } else {
            nums[i].val = nums.size() - i - 1;
        }
        nums[i].next = &nums[i+1];
    }
    nums.rbegin()->next = NULL;
}

void print_list(ListNode *p) {
    while (p != NULL) {
        std::cout << p->val << "->";
        p = p->next;
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    Solution s;

    assert(s.isPalindrome(NULL));
    vector<ListNode> nums;
    init_list(nums, 20);
    print_list(&nums[0]);
    assert(s.isPalindrome(&nums[0]));

    init_list(nums, 21);
    print_list(&nums[0]);
    assert(s.isPalindrome(&nums[0]));
    return 0;
}
#endif
