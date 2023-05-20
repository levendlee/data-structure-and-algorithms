class Solution(object):
    def maxMoves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        moves = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            moves[i][0] = 1
        for j in range(1, n):
            for i in range(m):
                cur = grid[i][j]
                from_up = (moves[i-1][j-1] + 1) if (i -1 >= 0 and cur > grid[i-1][j-1] and moves[i-1][j-1] != 0) else 0
                from_same = (moves[i][j-1] + 1) if (cur > grid[i][j-1] and moves[i][j-1] != 0) else 0
                from_down = (moves[i+1][j-1] + 1) if (i + 1 < m and cur > grid[i+1][j-1] and moves[i+1][j-1]!=0) else 0
                moves[i][j] = max(from_up, from_same, from_down)
        return max(max(row) for row in moves) - 1 
