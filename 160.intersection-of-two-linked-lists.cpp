/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (32.55%)
 * Total Accepted:    278.8K
 * Total Submissions: 856.3K
 * Testcase Example:  '8\n[4,1,8,4,5]\n[5,0,1,8,4,5]\n2\n3'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 * 
 * For example, the following two linked lists:
 * 
 * 
 * begin to intersect at node c1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA =
 * 2, skipB = 3
 * Output: Reference of the node with value = 8
 * Input Explanation: The intersected node's value is 8 (note that this must
 * not be 0 if the two lists intersect). From the head of A, it reads as
 * [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2
 * nodes before the intersected node in A; There are 3 nodes before the
 * intersected node in B.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3,
 * skipB = 1
 * Output: Reference of the node with value = 2
 * Input Explanation: The intersected node's value is 2 (note that this must
 * not be 0 if the two lists intersect). From the head of A, it reads as
 * [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes
 * before the intersected node in A; There are 1 node before the intersected
 * node in B.
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB =
 * 2
 * Output: null
 * Input Explanation: From the head of A, it reads as [2,6,4]. From the head of
 * B, it reads as [1,5]. Since the two lists do not intersect, intersectVal
 * must be 0, while skipA and skipB can be arbitrary values.
 * Explanation: The two lists do not intersect, so return null.
 * 
 * 
 * 
 * 
 * Notes:
 * 
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns.
 * You may assume there are no cycles anywhere in the entire linked
 * structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
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
#define SELFTEST
#include <cstddef>
#ifdef SELFTEST
#include <cassert>
#endif

#ifdef SELFTEST
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 设置a标记
        int lena = list_length(headA);
        int lenb = list_length(headB);
        
        ListNode *pa = headA, *pb = headB;
        if (lena > lenb) {
            pa = list_forward(headA, lena - lenb);
        }
        if (lenb > lena) {
            pb = list_forward(headB, lenb - lena);
        }
        return list_intersect(pa, pb);
    }

private:
    int list_length(ListNode *head) {
        ListNode *p = head;
        int len = 0;
        while (p != NULL) {
            len ++;
            p = p->next;
        }
        return len;
    }

    ListNode *list_forward(ListNode *head, int delta) {
        while (delta > 0) {
            head= head->next;
            delta --;
        }
        return head;
    }
    
    ListNode *list_intersect(ListNode *headA, ListNode *headB) {
        while(headA != NULL && headB != NULL) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

#ifdef SELFTEST
int main(int argc, char *argv[]) {
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    n2.next = &n1;
    n3.next = &n2;
    n4.next = &n1;

    Solution a;
    assert(a.getIntersectionNode(&n1, NULL) == NULL);
    assert(a.getIntersectionNode(NULL, &n1) == NULL);
    assert(a.getIntersectionNode(NULL, NULL) == NULL);
    assert(a.getIntersectionNode(&n3, &n4) == &n1);
    assert(a.getIntersectionNode(&n4, &n3) == &n1);
    assert(a.getIntersectionNode(&n4, &n2) == &n1);
    assert(a.getIntersectionNode(&n2, &n4) == &n1);
}
#endif
