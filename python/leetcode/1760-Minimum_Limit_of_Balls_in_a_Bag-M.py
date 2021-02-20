class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        lo = 1
        hi = max(nums)
        while lo < hi:
            ops = 0
            mid = (lo + hi) // 2
            for n in nums:
                ops += (n - 1) // mid
            if ops > maxOperations:
                lo = mid + 1
            else:
                hi = mid
        return lo
