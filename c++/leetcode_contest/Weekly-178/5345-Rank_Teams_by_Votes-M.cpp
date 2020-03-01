// 5345. Rank Teams by Votes
//https://leetcode.com/contest/weekly-contest-178/problems/rank-teams-by-votes/
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        const int n = votes[0].size();
        int has[26] = {0};
        vector<vector<int>> cnt(26, vector<int>(n, 0));
        for (auto& v : votes) {
            for (int i = 0; i < n; ++i) {
                has[v[i] - 'A']++;
                cnt[v[i] - 'A'][i]++;
            }
        }
        string res;
        for (int i = 0; i < 26; ++i) {
            char c = i + 'A';
            if (has[i]) res.push_back(c);
        }
        sort(res.begin(), res.end(),
            [&](const auto& l, const auto& r) {
                for (int i = 0; i < n; ++i) {
                    if (cnt[l-'A'] > cnt[r-'A']) return true;
                    else if (cnt[l-'A'] < cnt[r-'A']) return false;
                }
                return l < r;
            });
        return res;
    }
};