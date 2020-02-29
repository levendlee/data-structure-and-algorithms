# 1057 Campus Bikes
# https://leetcode.com/problems/campus-bikes

# version: 1; create time: 2019-10-19 17:35:14;
from heapq import heappush, heappop
from typing import List


class Solution:
    # Time:  O( mnlog(n) )
    # Space: O( mn )
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> List[int]:
        m, n = len(workers), len(bikes)

        def dist(i: int, j: int) -> int:
            return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1])

        # m * n log(n)
        heaps = [sorted((dist(i, j), j) for j in range(n)) for i in range(m)]

        match = [-1 for _ in range(m)]
        seen_w, seen_b = set(), set()
        for _ in range(m):
            mheap = []
            for i in range(m):
                if i in seen_w:
                    continue
                while heaps[i]:
                    d, j = heaps[i][0]
                    if j in seen_b:
                        heappop(heaps[i])
                        continue
                    heappush(mheap, (d, i, j))
                    break

            d, i, j = heappop(mheap)
            seen_w.add(i)
            seen_b.add(j)
            match[i] = j

        return match

