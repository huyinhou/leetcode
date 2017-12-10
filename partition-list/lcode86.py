import unittest

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def makeList(vals):
    node = ListNode(0)
    head = node
    for v in vals:
        head.next = ListNode(v)
        head = head.next
    return node.next

def compList(l1, l2):
    while l1 is not None and l2 is not None:
        if l1.val != l2.val:
            return False
        l1 = l1.next
        l2 = l2.next
    return l1 is None and l2 is None

def printList(l1):
    vals = []
    while l1 is not None:
        vals.append(l1.val)
        l1 = l1.next
    print vals

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        tmp = [None] * 2

        def compVal(v1, v2):
            if v1 < v2:
                return 0
            return 1

        while head is not None:
            idx = compVal(head.val, x)
            temp = head
            head = head.next
            temp.next = tmp[idx]
            tmp[idx] = temp
        
        retval = None
        for idx in range(1, -1, -1):
            temp = tmp[idx]
            while temp is not None:
                t = temp
                temp = temp.next
                t.next = retval
                retval = t

        return retval

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        ret = s.partition(makeList([1, 4, 3, 2, 5, 2]), 3)
        printList(ret)
        self.assertTrue(compList(ret, makeList([1, 2, 2, 4, 3, 5])))
        self.assertTrue(compList(s.partition(None, 3), None))
        self.assertTrue(compList(s.partition(makeList([3, 4, 5, 6, 1, 2]), 3), 
            makeList([1, 2, 3, 4, 5, 6])))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()