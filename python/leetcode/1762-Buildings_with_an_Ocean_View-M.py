class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        res = []
        max_h = 0
        n = len(heights)
        for i, h in enumerate(reversed(heights)):
            i = n - 1 - i
            if h > max_h:
                res.append(i)
            max_h = max(h, max_h)
        return list(reversed(res))