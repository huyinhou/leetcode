import unittest

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def equalsTo(self, head):
        l = self
        r = head
        while l is not None and r is not None:
            if l.val != r.val:
                return False
            l = l.next
            r = r.next
        return l is None and r is None

def makeList(vals):
    node = ListNode(0)
    temp = node
    for v in vals:
        temp.next = ListNode(v)
        temp = temp.next
    return node.next

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        p1 = head
        p2 = head.next
        while p2 is not None:
            p1.val, p2.val = p2.val, p1.val
            p1 = p2.next
            p2 = None
            if p1 is not None:
                p2 = p1.next
        return head

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        ret = s.swapPairs(makeList([1, 2, 3]))
        self.assertTrue(ret.equalsTo(makeList([2, 1, 3])))
        ret = s.swapPairs(makeList([1,]))
        self.assertTrue(ret.equalsTo(makeList([1,])))
        ret = s.swapPairs(makeList([1, 2, 3, 4, 5, 6, 7]))
        self.assertTrue(ret.equalsTo(makeList([2, 1, 4, 3, 6, 5, 7])))
        
def main():
    unittest.main()

if __name__ == '__main__':
    main()