class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        accu = 0
        min_diff, max_diff = 0, 0
        for d in differences:
            accu += d
            min_diff = min(min_diff, accu)
            max_diff = max(max_diff, accu)
        starting = lower - min_diff
        ending = upper - max_diff
        return max(ending - starting + 1, 0)
