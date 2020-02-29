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
