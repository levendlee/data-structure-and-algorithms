class Solution(object):
    def maxArrayValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        res = nums[n-1]
        cur = nums[n-1]
        for i in range(n-2, -1, -1):
            if nums[i] <= nums[i + 1] or cur >= nums[i]:
                cur += nums[i]
            else:
                cur = nums[i]
            res = max(res, cur)
        return res
