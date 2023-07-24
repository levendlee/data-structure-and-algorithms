class Solution(object):
    def maximumJumps(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        
        max_jumps = [-1] * n
        max_jumps[0] = 0

        for j in range(1, n):
            for i in range(0, j):
                if max_jumps[i] >= 0 and -target <= nums[j] - nums[i] <= target:
                    max_jumps[j] = max(max_jumps[j], max_jumps[i] + 1)
        
        return max_jumps[n - 1]
