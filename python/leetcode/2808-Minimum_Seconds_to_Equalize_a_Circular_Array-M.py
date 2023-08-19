import collections

class Solution(object):
    def minimumSeconds(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        res = n

        ind = collections.defaultdict(list)
        for idx, num in enumerate(nums):
            ind[num].append(idx)
        for num, idx_list in ind.items():
            max_dist = 0
            if len(idx_list) == 1:
                max_dist = n / 2
            else:
                for i in range(len(idx_list) - 1):
                    max_dist = max(((idx_list[i + 1] - idx_list[i] - 1) + 1) / 2, max_dist)
                max_dist = max(((idx_list[0] + n - idx_list[-1] - 1) + 1) / 2, max_dist)
            print(num, max_dist)
            res = min(res, max_dist)

        return res
        
