class Solution(object):
    def findScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        score = 0
        marked = [False for _ in range(len(nums) + 2)]
        for num, idx in sorted((n, i) for i, n in enumerate(nums)):
            if marked[idx + 1]:
                continue
            score += num
            marked[idx] = True
            marked[idx + 1] = True
            marked[idx + 2] = True
        return score
