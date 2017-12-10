# Definition for singly-linked list.
import unittest

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def rotateRange(self, head, tail):
        temp  = tail
        while head != tail:
            next = head.next
            head.next = temp
            temp = head
            head = next
        return temp

    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        # print head, k
        if head is None:
            return None

        temp = head
        count = 0
        while temp is not None:
            count += 1
            temp = temp.next
        
        k %= count
        if k == 0:
            return head
        head = self.rotateRange(head, None)
        # printList(head)
        tail = head
        for i in range(1, k):
            tail = tail.next
        tail.next = self.rotateRange(tail.next, None)
        head = self.rotateRange(head, tail.next)
        # printList(head)
        
        return head
        
def makeList(vals):
    node = ListNode(0)
    temp = node
    for v in vals:
        temp.next = ListNode(v)
        temp = temp.next
    return node.next

def listEqual(l1, l2):
    # print "l1:"
    # printList(l1)
    # print "l2:"
    # printList(l2)
    while l1 is not None and l2 is not None:
        if l1.val != l2.val:
            return False
        l1 = l1.next
        l2 = l2.next
    return l1 is None and l2 is None

def printList(l1):
    temp = []
    while l1 is not None:
        temp.append(l1.val)
        l1 = l1.next
    print temp

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertTrue(listEqual(
            s.rotateRight(makeList([1, 2, 3, 4, 5]), 1),
            makeList([5, 1, 2, 3, 4])))
        self.assertTrue(listEqual(
            s.rotateRight(makeList([1, 2, 3, 4, 5]), 2),
            makeList([4, 5, 1, 2, 3])))
        self.assertTrue(listEqual(
            s.rotateRight(makeList([1, 2, 3, 4, 5]), 3),
            makeList([3, 4, 5, 1, 2])))
        self.assertTrue(listEqual(
            s.rotateRight(makeList([1, 2, 3, 4, 5, 6]), 6),
            makeList([1, 2, 3, 4, 5, 6])))
        self.assertTrue(listEqual(
            s.rotateRight(makeList([1, 2, 3, 4, 5, 6]), 2),
            makeList([5, 6, 1, 2, 3, 4])))
def main():
    unittest.main()

if __name__ == '__main__':
    main()