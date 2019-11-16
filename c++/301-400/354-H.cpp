class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(),
                 [](const auto& l, const auto& r) { return l[0] < r[0] || (l[0] == r[0] && l[1] > r[1]); } );
        std::vector<int> dp;
        for (auto& e : envelopes) {
            auto idx = std::lower_bound(dp.begin(), dp.end(), e[1]) - dp.begin();
            if(idx == 0 || dp.empty() || dp[idx - 1] < e[1]) {
                if (idx == dp.size()) {
                    dp.push_back(e[1]);
                } else {
                    dp[idx] = e[1];
                }
            }
        }
        return dp.size();
    }
};