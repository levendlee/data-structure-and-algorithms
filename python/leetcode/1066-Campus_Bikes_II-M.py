# 1066 Campus Bikes II
# https://leetcode.com/problems/campus-bikes-ii

# version: 1; create time: 2019-10-19 17:00:44;
from heapq import heappop, heappush
from typing import List


class BFSSolution:
    # BFS
    def assignBikes(self, workers: List[List[int]],
                    bikes: List[List[int]]) -> int:
        m, n = len(workers), len(bikes)

        dist = [[abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1])
                 for j in range(n)] for i in range(m)]

        heap = [(0, 0, 0)]
        seen = set()
        while heap:
            d, i, s = heappop(heap)
            if s in seen:
                continue
            seen.add(s)
            if i == m:
                return d
            for j in range(n):
                if s & (1 << j):
                    continue
                nd = d + dist[i][j]
                heappush(heap, (nd, i + 1, s | (1 << j)))


class DFSSolution:
    # DFS
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        m, n = len(workers), len(bikes)

        dist = [[abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1])
                 for j in range(n)] for i in range(m)]

        dp = [[0 for _ in range(1 << n)]]
        dp.extend([[float('inf') for _ in range(1 << n)] for _ in range(m)])

        for i in range(m):
            for s in range(1 << n):
                for j in range(n):
                    if s & (1 << j):
                        continue
                    ns = s | (1 << j)
                    dp[i + 1][ns] = min(dp[i + 1][ns], dp[i][s] + dist[i][j])

        return dp[-1][-1]

