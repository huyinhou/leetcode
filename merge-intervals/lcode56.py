import unittest

class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

    def __str__(self):
        return "(%d, %d)" % (self.start, self.end)

    def __repr__(self):
        return self.__str__()

def cmpInterval(l, r):
    if l.start > r.start:
        return 1
    elif l.start == r.start:
        return 0
    return -1

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        # intervals.sort(cmpInterval)
        intervals = sorted(intervals, key = lambda x : x.start)
        for i in range(len(intervals)):
            j = i + 1
            while j < len(intervals):
                if intervals[j].start <= intervals[i].end:
                    intervals[i].end = max(intervals[i].end, intervals[j].end)
                    del intervals[j]
                else:
                    break
        return intervals

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        intervals = []
        intervals.append(Interval(2, 6))
        intervals.append(Interval(3, 5))
        intervals.append(Interval(1, 3))
        intervals.append(Interval(1, 2))
        intervals.append(Interval(8, 10))
        intervals.append(Interval(15, 18))
        ret = s.merge(intervals)
        for a in ret:
            print a

        intervals = []
        intervals.append(Interval(1, 4))
        intervals.append(Interval(0, 4))
        ret = s.merge(intervals)
        for a in ret:
            print a

def main():
    unittest.main()

if __name__ == '__main__':
    main()