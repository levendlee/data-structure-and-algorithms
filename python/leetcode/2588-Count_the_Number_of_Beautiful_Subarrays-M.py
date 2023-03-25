import collections

class Solution(object):
    def beautifulSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = 0
        xor_cnts = collections.defaultdict(int)
        xor_cnts[0] = 1

        x = 0
        for n in nums:
            x ^= n
            cnt += xor_cnts[x]
            xor_cnts[x] += 1
        return cnt
