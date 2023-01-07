class Solution(object):
    def maximumTastiness(self, price, k):
        """
        :type price: List[int]
        :type k: int
        :rtype: int
        """
        price = sorted(price)
        hi, lo = price[-1] - price[0], 0

        n = len(price)
        dp = [1 for i in range(n)]

        while lo < hi:
            # print(hi, lo)
            mid = (lo + hi + 1) // 2
            i = 0
            max_dp = 1
            for j in range(n):
                dp[j] = 1
                if price[j] - price[i] < mid:
                    continue
                while price[j] - price[i] >= mid:
                    dp[j] = max(dp[j], dp[i] + 1)
                    i += 1
                max_dp = max(max_dp, dp[j])
            if max_dp >= k:
                lo = mid
            else:
                hi = mid - 1
        return lo
