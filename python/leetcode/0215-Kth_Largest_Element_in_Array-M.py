class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        '''
        heap = []
        for n in nums:
            heapq.heappush(heap, n)
            while len(heap) > k:
                heapq.heappop(heap)
        kth = heapq.heappop(heap)
        return kth
        '''

        def quick_select(lo, hi):
            pick = nums[lo]
            smaller, larger = [], []
            for n in nums[lo + 1: hi + 1]:
                if n <= pick:
                    smaller.append(n)
                else:
                    larger.append(n)
            loc = lo + len(larger)
            nums[lo: hi + 1] = larger + [pick] + smaller
            if loc == k - 1:
                return nums[loc]
            elif loc < k - 1:
                return quick_select(loc + 1, hi)
            else:
                return quick_select(lo, loc - 1)
        
        return quick_select(0, len(nums) - 1)