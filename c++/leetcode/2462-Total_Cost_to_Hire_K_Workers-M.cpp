class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {   
        const int n = costs.size();

        priority_queue<pair<int, int>> pq;
        int i = 0, j = n - 1;
        while (i <= j && pq.size() < 2 * candidates) {
            pq.push({-costs[i], -(i++)});
            if (i > j) break;
            pq.push({-costs[j], -(j--)});
        }
        
        long long total_cost = 0;
        while (k-- > 0) {
            auto [ncost, nidx] = pq.top();
            pq.pop();
            int cost = -ncost, idx = -nidx;
            total_cost += cost;
            if (i <= j) {
                idx = (idx >= i) ? j-- : i++;
                pq.push({-costs[idx], -idx});
            }
        }

        return total_cost;
    }
};
