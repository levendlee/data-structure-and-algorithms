class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        # sort events based on end times
        sorted_events = sorted(events, key=lambda x: x[1])
        sorted_timestamps = sorted(set(e[0] for e in events).union(
                                 set(e[1] for e in events)))
        sorted_timestamps_index = {t : i for i, t in enumerate(sorted_timestamps)}
        
        def get_index(timestamp):
            return sorted_timestamps_index[timestamp]
        
        # dynamic programming with the maximum scores of k attended events
        m, n = len(sorted_events), len(sorted_timestamps)
        dp = [[0 for _ in range(k)] for _ in range(n)]
        
        last_index = -1
        def fill_values(index):
            nonlocal last_index
            for i in range(last_index + 1, index + 1):
                dp[i] = list(dp[last_index])
            last_index = index
                
        for i, event in enumerate(sorted_events):
            start, end, value = event
            start_idx, end_idx = get_index(start), get_index(end)
            fill_values(end_idx)
            for j in range(k-1, -1, -1):
                dp[end_idx][j] = max(dp[end_idx][j], 
                                     (dp[start_idx - 1][j-1] if j > 0 and start_idx > 0 else 0) + value)
        
        return max(max(row) for row in dp)
