class Solution(object):
    def repairCars(self, ranks, cars):
        """
        :type ranks: List[int]
        :type cars: int
        :rtype: int
        """
        lo = 0
        hi = max(ranks) * cars * cars
        while lo < hi:
            mid = (lo + hi) // 2
            num_cars = 0
            for r in ranks:
                num_cars += floor(sqrt(mid / r))
            if num_cars >= cars:
                hi = mid
            else:
                lo = mid + 1
        return lo
