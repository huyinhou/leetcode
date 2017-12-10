import unittest


# Employee info
class Employee(object):
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates

class Solution(object):
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        employemap = {}
        for e in employees:
            employemap[e.id] = e
        ids = [id,]
        total = 0
        while len(ids) > 0:
            subids = []
            for i in ids:
                ei = employemap[i]
                subids.extend(ei.subordinates)
                total += ei.importance
            ids = subids
        return total

class TestSolution(unittest.TestCase):
    def test_1(self):
        e1 = Employee(1, 5, [2, 3])
        e2 = Employee(2, 3, [])
        e3 = Employee(3, 3, [])
        s = Solution()
        self.assertEqual(s.getImportance([e1, e2, e3], 1), 11)
        pass


def main():
    unittest.main()

if __name__ == '__main__':
    main()