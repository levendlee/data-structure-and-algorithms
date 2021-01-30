_perfectBoxes_cache = {}
def perfectBoxes(h: int) -> int:
    if h in _perfectBoxes_cache:
        return _perfectBoxes_cache[h]
    if h == 1:
        return 1
    cnt = perfectBoxes(h - 1) + baseArea(h)
    _perfectBoxes_cache[h] = cnt
    return cnt

def baseArea(h : int) -> int:
    cnt = ((1 + h) * h) // 2
    return cnt

class Solution:
    def minimumBoxes(self, n: int) -> int:
        perfectBoxesRes = []
        max_height = 1
        for i in range(1, n + 1):
            cnt = perfectBoxes(i)
            max_height = i
            if cnt == n:
                return i
            if cnt > n:
                break
        res = baseArea(max_height)
        capacity = perfectBoxes(max_height)
        for i in range(max_height):
            capacity -= max_height - i
            if capacity >= n:
                res -= 1
            else:
                break
        return res
