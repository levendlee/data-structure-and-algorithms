class SparseVector:
    def __init__(self, nums: List[int]):
        v = []
        for i, n in enumerate(nums):
            if n:
                v.append((i, n))
        self._v = v

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        res = 0
        v0, v1 = self._v, vec._v
        m, n = len(v0), len(v1)
        i, j = 0, 0
        while i < m and j < n:
            if v0[i][0] > v1[j][0]:
                j += 1
            elif v0[i][0] < v1[j][0]:
                i += 1
            else:
                res += v0[i][1] * v1[j][1]
                i += 1
                j += 1
        return res
