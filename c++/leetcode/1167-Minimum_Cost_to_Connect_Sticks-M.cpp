// 1167 Minimum Cost to Connect Sticks
// https://leetcode.com/problems/minimum-cost-to-connect-sticks

// version: 1; create time: 2019-12-30 11:34:15;
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
