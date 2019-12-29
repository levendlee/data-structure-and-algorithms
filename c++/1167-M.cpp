class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        std::priority_queue<int> pq;
        for (const auto& s : sticks) {
            pq.push(-s);
        }
        int cost = 0;
        while (pq.size() > 1) {
            const auto s0 = -pq.top(); pq.pop();
            const auto s1 = -pq.top(); pq.pop();
            const auto s = s0 + s1;
            cost += s;
            pq.push(-s);
        }
        return cost;
    }
};