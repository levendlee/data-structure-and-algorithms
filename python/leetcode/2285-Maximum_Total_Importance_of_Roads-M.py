class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        weights = [0 for _ in range(n)]
        for r in roads:
            weights[r[0]] += 1
            weights[r[1]] += 1
        return sum(i * w for i, w in zip(range(n, 0, -1), reversed(sorted(weights))))
