import unittest

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        temp = head
        while temp is not None and temp.next is not None:
            head = head.next
            temp = temp.next.next
            if head == temp:
                return True
        return False

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertFalse(s.hasCycle(None))

        p = ListNode(1)
        p.next = ListNode(2)
        self.assertFalse(s.hasCycle(p))

        q = ListNode(3)
        q.next = p.next
        p.next.next = q
        self.assertTrue(s.hasCycle(p))

        q.next = p
        self.assertTrue(s.hasCycle(p))

if __name__ == '__main__':
    unittest.main()