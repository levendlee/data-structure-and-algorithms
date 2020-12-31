class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        def get_score(x, y0, y1):
            return grid[x][y0] if y0 == y1 else grid[x][y0] + grid[x][y1]
        m, n = len(grid), len(grid[0])
        memo = dict()
        memo[(0, n-1)] = get_score(0, 0, n-1)
        for x in range(1, m):
            next_memo = dict()
            for y0 in range(n):
                for y1 in range(n):
                    score = -1
                    cells = get_score(x, y0, y1)
                    # for py0 in range(max(0, y0 - 1), min(n, y0 + 2)):
                    #    for py1 in range(max(0, y1 - 1), min(n, y1 + 2)):
                    for py0 in range(y0 - 1, y0 + 2):
                        for py1 in range(y1 - 1, y1 + 2):
                            if (py0, py1) in memo:
                                score = max(score, memo[(py0, py1)] + cells)
                    if score >= 0:
                        next_memo[(y0, y1)] = score
            if x == m - 1:
                return max(next_memo.values())
            else:
                memo = next_memo
