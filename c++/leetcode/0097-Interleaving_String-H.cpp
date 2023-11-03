// 97 Interleaving String
// https://leetcode.com/problems/interleaving-string

// version: 1; create time: 2019-10-26 15:12:59;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int n1 = s1.size();
        const int n2 = s2.size();
        const int n3 = s3.size();

        if (n3 != (n1+ n2)) return false;
        if (n1 == 0) return s3 == s2;
        if (n2 == 0) return s3 == s1;

        set<pair<int, int>> cur_ptrs{{-1, -1}};
        set<pair<int, int>> nex_ptrs;

        for (const auto c: s3) {
            for (const auto& p: cur_ptrs) {
                const auto l_ptr = p.first;
                const auto r_ptr = p.second;
                if (((l_ptr + 1) < n1) && (s1[l_ptr + 1] == c)) {
                    nex_ptrs.emplace(l_ptr + 1, r_ptr);
                }
                if (((r_ptr + 1) < n2) && (s2[r_ptr + 1] == c)) {
                    nex_ptrs.emplace(l_ptr, r_ptr + 1);
                }
            }
            if (nex_ptrs.empty()) return false;
            cur_ptrs = std::move(nex_ptrs);
        }

        return true;
    }
};

// 2023/11/02

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int n1 = s1.size();
        const int n2 = s2.size();
        const int n3 = s3.size();
        if (n3 != n1 + n2) return false;
        if (n3 == 0) return true;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n3; ++i) {
            for (int j = 0; j <= n1; ++j) {
                int k = i - j;
                if (k < 0 || k > n2) continue;

                dp[j][k] = (j > 0 && s1[j-1] == s3[i-1] && dp[j-1][k]) ||
                           (k > 0 && s2[k-1] == s3[i-1] && dp[j][k-1]);

                if (i == n3 && dp[j][k]) return true;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int n1 = s1.size();
        const int n2 = s2.size();
        const int n3 = s3.size();
        if (n3 != n1 + n2) return false;
        if (n1 == 0) return s2 == s3;
        if (n2 == 0) return s1 == s3;

        set<pair<int, int>> cur_ptrs, nex_ptrs;
        cur_ptrs.insert({0, 0});

        while (!cur_ptrs.empty()) {
            nex_ptrs.clear();
            for (auto& [l, r] : cur_ptrs) {
                int d = l + r;
                if (d == n3) return true;
                if (l + 1 <= n1 && s1[l] == s3[d]) {
                    nex_ptrs.insert({l + 1, r});
                }
                if (r + 1 <= n2 && s2[r] == s3[d]) {
                    nex_ptrs.insert({l, r + 1});
                }
            }
            cur_ptrs = nex_ptrs;
        }

        return false;
    }
};
