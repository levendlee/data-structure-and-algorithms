class Solution:
    def toColumnMajor(self, matrix):
        m, n = len(matrix), len(matrix[0])
        return [[matrix[i][j] for i in range(m)] for j in range(n)]
    
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        return self.largestSubmatrixImpl1(matrix)
    
    # Space: O(N^2); Time: O(N^3)
    def largestSubmatrixImpl0(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        matrix= self.toColumnMajor(matrix)
        ranges = collections.defaultdict(int)
        for col in matrix:
            sums = [0]
            for elem in col:
                sums.append(sums[-1] + elem)
            for s in range(m):
                for e in range(s + 1, m + 1):
                    if sums[e] - sums[s] == e - s:
                        ranges[(s, e)] += 1
        largest = 0
        for (s, e), cnt in ranges.items():
            largest = max(largest, (e - s) * cnt)
        return largest
    
    # Space: O(N^2); Time: O(N^2LogN)
    def largestSubmatrixImpl1(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        heights = [[0 for _ in range(n)] for _ in range(m)]
        for j in range(n):
            h = 0
            for i in range(m):
                h =  h + 1 if matrix[i][j] == 1 else 0
                heights[i][j] = h
        largest = 0
        for i in range(m):
            heights[i] = sorted(heights[i], reverse=True)
            for j in range(n):
                largest = max(largest, (j + 1) * heights[i][j])
        return largest
