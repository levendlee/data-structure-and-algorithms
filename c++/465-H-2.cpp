class Solution {
private:
    int min_trans_;
public:
    void tryTransfer(vector<int>& balances, int i, int trans) {
        const int n = balances.size();
        //cout << i << "," << n << "\n";
        if (trans >= min_trans_) {
            return;
        }
        while (i < n && balances[i] == 0) ++i;
        if (i == n) {
            min_trans_ = trans;
            return;
        }
        for (int j = n - 1; j >= 0; --j) {
            if (balances[j] == 0) continue;
            auto pay = min(abs(balances[i]), balances[j]);
            balances[i] += pay;
            balances[j] -= pay;
            tryTransfer(balances, i, trans + 1);
            balances[i] -= pay;
            balances[j] += pay;
        }
    }

    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balances;
        for (const auto& trans : transactions) {
            balances[trans[0]] += trans[2];
            balances[trans[1]] -= trans[2];
        }

        int trans = 0;
        unordered_map<int, int> balances_cnt;
        for (const auto& p : balances) {
            if (p.second != 0) {
                int b = p.second;
                if (balances_cnt[-b] > 0) {
                    balances_cnt[-b]--;
                    trans++;
                } else {
                    balances_cnt[b]++;
                }
            }
        }
        vector<int> balances_vec;
        for (const auto& p : balances_cnt) {
            for (int i = 0; i < p.second; ++i) {
                balances_vec.push_back(p.first);
            }
        }
        sort(balances_vec.begin(), balances_vec.end());

        min_trans_ = INT_MAX;
        tryTransfer(balances_vec, 0, trans);
        return min_trans_;
    }
};