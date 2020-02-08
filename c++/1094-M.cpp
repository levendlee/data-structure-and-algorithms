class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::sort(trips.begin(), trips.end(),
                 [](const auto& lhs, const auto& rhs) {
                     return lhs[1] < rhs[1];
                 });
        priority_queue<pair<int, int>> pq;
        int riders = 0;
        for (const auto& t : trips) {
            while (!pq.empty() && -pq.top().first <= t[1]) {
                riders -= pq.top().second; pq.pop();
            }
            riders += t[0];
            if (riders > capacity) return false;
            pq.push({-t[2], t[0]});
        }
        return true;
    }
};