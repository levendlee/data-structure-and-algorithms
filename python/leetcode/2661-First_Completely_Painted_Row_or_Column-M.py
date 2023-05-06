class Solution(object):
    def firstCompleteIndex(self, arr, mat):
        """
        :type arr: List[int]
        :type mat: List[List[int]]
        :rtype: int
        """
        n_row, n_col = len(mat), len(mat[0])
        c_row = [0 for _ in range(n_row)]
        c_col = [0 for _ in range(n_col)]
        indices = {}
        for i, row in enumerate(mat):
            for j, elem in enumerate(row):
                indices[elem] = (i, j)
        for k, elem in enumerate(arr):
            i, j = indices[elem]
            c_row[i] += 1
            c_col[j] += 1
            if c_row[i] == n_col or c_col[j] == n_row:
                return k
        return len(arr) - 1
