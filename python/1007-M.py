from typing import List


class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        n = len(A)

        counter = [0 for i in range(6)]
        for i in range(n):
            counter[A[i] - 1] += 1
            if A[i] == B[i]:
                continue
            counter[B[i] - 1] += 1

        candidates = set(idx for idx, cnt in enumerate(counter) if cnt == n)

        if not candidates:
            return -1

        def calcMinRotation(seq: List[int]):
            dct = [0 for i in range(6)]
            for elem in seq:
                dct[elem - 1] += 1
            return n - max((count for elem, count in enumerate(dct) if elem in candidates),
                           default=0)

        return min(calcMinRotation(A), calcMinRotation(B))
