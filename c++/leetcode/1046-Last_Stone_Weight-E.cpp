// 1046 Last Stone Weight
// https://leetcode.com/problems/last-stone-weight

// version: 1; create time: 2020-01-11 17:37:02;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq;
        for (const auto& s : stones) {
            pq.push(s);
        }
        while (pq.size() >= 2) {
            const auto y = pq.top(); pq.pop();
            const auto x = pq.top(); pq.pop();
            if (y != x) {
                pq.push(y - x);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
