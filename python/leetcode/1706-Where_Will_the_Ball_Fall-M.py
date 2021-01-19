class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        fall = list(range(n))
        for i in range(m):
            next_fall = [-1 for _ in range(n)]
            for j in range(n):
                if grid[i][j] == 1:
                    if j > 0 and grid[i][j-1] == 1:
                        next_fall[j] = fall[j-1]
                else:
                    if j + 1 < n and grid[i][j+1] == -1:
                        next_fall[j] = fall[j+1]
            fall = next_fall
        res = [-1 for _ in range(n)]
        for j, ball in enumerate(fall):
            if ball != -1:
                res[ball] = j
        return res
