class Solution {
private:
    int min_trans_;
public:
    void dfs(vector<int>& balances, int i, int t) {
        const int n = balances.size();
        if (t >= min_trans_) {
            return;
        }
        while (i < n && balances[i] <= 0) {
            ++i;
        }
        if (i == n) {
            min_trans_ = t;
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            if (balances[i] > 0 && balances[j] < 0) {
                int trans = std::min(balances[i], -balances[j]);
                balances[i] -= trans;
                balances[j] += trans;
                dfs(balances, i, t + 1);
                balances[i] += trans;
                balances[j] -= trans;
            }
        }
    }

    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balances;
        for (auto& t: transactions) {
            balances[t[0]] += t[2];
            balances[t[1]] -= t[2];
        }

        vector<int> balances_v;
        for (auto& p : balances) {
            if (p.second != 0) {
                balances_v.push_back(p.second);
            }
        }

        min_trans_ = INT_MAX;
        dfs(balances_v, 0, 0);

        return min_trans_;
    }
};