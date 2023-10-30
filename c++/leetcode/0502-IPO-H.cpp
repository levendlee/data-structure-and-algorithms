class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        /*
        const int n = profits.size();
        vector<int> indicies(n);
        iota(indicies.begin(), indicies.end(), 0);
        sort(indicies.begin(), indicies.end(),
            [&](int i, int j) { return capital[i] < capital[j]; });
        
        vector<int> max_profit(k + 1, w);
        for (int i : indicies) {
            for (int j = k - 1; j >= 0; --j) {
                if (capital[i] <= max_profit[j]) {
                    max_profit[j + 1] = std::max(max_profit[j] + profits[i], max_profit[j + 1]);
                }
            }
        }

        return *std::max_element(max_profit.begin(), max_profit.end());
        */
        const int n = profits.size();
        vector<int> indicies(n);
        iota(indicies.begin(), indicies.end(), 0);
        sort(indicies.begin(), indicies.end(),
            [&](int i, int j) { return capital[i] < capital[j]; });
        
        
        int idx = 0;
        priority_queue<int> pq;
        for (int i = 0; i < k; ++i) {
            while (idx < n && capital[indicies[idx]] <= w) {
                pq.push(profits[indicies[idx++]]);
            }
            if (pq.empty()) return w;
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};
